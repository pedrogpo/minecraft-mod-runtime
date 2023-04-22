#include "mod.hpp"
#include "../sdk/abstract/fields.hpp"

bool mod::c_mod::attach() {
	const auto created_java_vms = wrapper::jni::get_created_java_vms(&this->jvm);

	if (!created_java_vms) {
		log_debug("Failed to get created java vms");
		return false;
	}

	const auto attach_status = this->jvm->AttachCurrentThreadAsDaemon(reinterpret_cast<void**>(&this->env), nullptr);
	if (attach_status != JNI_OK) {
		log_debug("Failed to attach to java vm");
		return false;
	}

	return true;
}

bool mod::c_mod::get_version() {
	// Get game handle
	const auto game_handle = utils::game::get_game_handle();

	// Get game title
	char game_title[256];
	GetWindowTextA(game_handle, game_title, sizeof(game_title));

	// get mc version
	const auto mc_version = [&]() -> const char* {
		for (const auto& version : this->m_versions) {
			if (strstr(game_title, version)) {
				return version;
			}
		}

		return nullptr;
	}();

	// Check if version is supported
	if (!mc_version) {
		log_debug("Unsupported version");
		return false;
	}

	log_debug("Game version: %s", mc_version);

	this->m_version = mc_version;

	return true;
}

void mod::c_mod::initialize() {
	// Get minecraft version
	if (!this->get_version()) {
		log_debug("Failed to get minecraft version");
		return;
	}
	
	// Attach to java vm
	if (!this->attach()) {
		log_debug("Failed to attach to java vm");
		return;
	}

	// Initialize mapper
	sdk::g_mapper = std::make_unique<sdk::c_mapper>(this->env);

	if (!sdk::g_mapper->init()) {
		log_debug("Failed to initialize mapper");
		return;
	}

	const auto& mc_class = sdk::g_mapper->classes["Minecraft"];
	const auto mc_obj = env->CallStaticObjectMethod(mc_class->get_class(), mc_class->methods["getMinecraft"]);
	// Wait for delete key
	while (!GetAsyncKeyState(VK_DELETE)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	
	env->DeleteLocalRef(mc_obj);
}

void mod::c_mod::shutdown() {
	// sleep for 1s to prevent crash and show debug messages
	std::this_thread::sleep_for(std::chrono::seconds(1));
	
	sdk::g_mapper->destroy();
	this->jvm->DetachCurrentThread();
}

extern std::unique_ptr<mod::c_mod> g_instance;