#include "mod.hpp"

bool mod::c_mod::attach() {
	const auto created_java_vms = wrapper::jni::get_created_java_vms(&this->jvm);

	if (!created_java_vms) {
		log_debug("Failed to get created java vms");
		return false;
	}

	const auto attach_status = this->jvm->AttachCurrentThread(reinterpret_cast<void**>(&this->env), nullptr);
	if (attach_status != JNI_OK) {
		log_debug("Failed to attach to java vm");
		return false;
	}

	return true;
}

void mod::c_mod::initialize() {
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

	// Wait for delete key
	while (!GetAsyncKeyState(VK_DELETE)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void mod::c_mod::shutdown() {
	sdk::g_mapper->destroy();
	this->jvm->DetachCurrentThread();
}

extern std::unique_ptr<mod::c_mod> g_instance;