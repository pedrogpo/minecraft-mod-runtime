#include "mapper.hpp"

bool sdk::c_mapper::init() {
	// Get game handle
	const auto game_handle = utils::game::get_game_handle();

	// Get game title
	char game_title[256];
	GetWindowTextA(game_handle, game_title, sizeof(game_title));

	// get mc version
	const auto mc_version = get_minecraft_version(game_title);
	
	// Check if version is supported
	if (!mc_version) {
		log_debug("Unsupported version");
		return false;
	}

	log_debug("Game version: %s", mc_version);

	this->current_version = mc_version;

	// Get classloader
	this->m_class_loader = this->env->NewGlobalRef(sdk::g_wrapper->get_class_loader(this->env));

	if (!this->m_class_loader) {
		log_debug(xor ("Failed to get class loader"));
		return false;
	}

	this->env->ExceptionClear();

    return true;
}

void sdk::c_mapper::destroy() {
	this->env->DeleteGlobalRef(m_class_loader);
}

const char* sdk::c_mapper::get_minecraft_version(const char* title) {
	for (auto& m_version : m_versions) {
		if (strstr(title, m_version)) {
			return m_version;
		}
	}

	return nullptr;
}

/**
	@brief Register a class and its versions in the cheat
	This function registers a class and its versions in the cheat. Each class can have different versions, so this function allows to register them together in a convenient way.
	@param class_name The name of the class to register. (unique_identifier)
	@param versions A vector containing a version list to try before giving up.
	@param 1_7 Classname of the 1.7.10 vanilla version
	@param 1_8 Classname of the 1.8.9 vanilla version
	@return void
*/
void sdk::c_mapper::register_class(const char* name, std::vector<sdk::s_try_class> try_list, const char* v1_7, const char* v1_8, bool env_classfinder) {
	// Get class
	jclass cls = env_classfinder ? env->FindClass(try_list[0].cls) : nullptr;

	for (const auto& try_class : try_list) {
		for (const auto& mc_version : try_class.mc_version) {
			if (strstr(current_version, mc_version)) {
				cls = sdk::g_wrapper->find_class(this->env, try_class.cls, this->m_class_loader);

				// If the first call fails, try again with replaced slashes
				if (!cls && try_class.replace_slashs) {
					const auto class_name = utils::string::replace_all(try_class.cls, xor ("/"), xor ("."));
					cls = sdk::g_wrapper->find_class(this->env, class_name.c_str(), this->m_class_loader);
				}
				
				// Break out of the loop if the class was found
				break;
			}
		}

		// If a class was found, exit the loop
		if (cls) break;
	}

	// If no class was found, attempt to find a default class based on the current Minecraft version
	if (!cls) {
		if (strstr(current_version, xor ("1.7.10")) && v1_7) {
			cls = sdk::g_wrapper->find_class(this->env, v1_7, this->m_class_loader);
		}
		else if (strstr(current_version, xor ("1.8.8")) || strstr(current_version, xor ("1.8.9")) && v1_8) {
			cls = sdk::g_wrapper->find_class(this->env, v1_8, this->m_class_loader);
		}
	}

	// If still no class was found, log an error and return
	if (!cls) {
		log_err(xor ("Failed to find class %s"), name);
		return;
	}

	// Create new class
	auto c_class = std::make_shared<sdk::c_class>(name, cls);

	// Add class to map
	this->classes.insert(std::make_pair(name, c_class));
	
	log_ok(xor ("Registered class [%s] - %p"), name, cls);
}

std::unique_ptr<sdk::c_mapper> sdk::g_mapper;