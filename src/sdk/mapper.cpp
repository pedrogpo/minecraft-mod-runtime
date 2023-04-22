#include "mapper.hpp"
#include <string_view>

bool sdk::c_mapper::init() {
	// Get classloader
	this->m_class_loader = this->env->NewGlobalRef(sdk::g_wrapper->get_class_loader(this->env));

	if (!this->m_class_loader) {
		log_debug(xor ("Failed to get class loader"));
		return false;
	}

	for (const auto& cls : mappings_classes) {
		this->register_class(cls.first,
			cls.second.try_list,
			cls.second.vanilla_mappings
		);
	}

	for (const auto& cls : mappings_methods) {
		const auto& mapped_cls = this->classes[cls.first.c_str()];
		if (!mapped_cls)
			continue;

		for (const auto& method : cls.second) {
			mapped_cls->register_method(method.first.c_str(), method.second);
		}
	}

	this->env->ExceptionClear();

    return true;
}

void sdk::c_mapper::destroy() {
	this->env->DeleteGlobalRef(m_class_loader);
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
void sdk::c_mapper::register_class(const char* name, std::vector<s_try_class> try_list, std::vector<s_vanilla_mapping> vanilla_mappings, bool env_classfinder) {
	const auto current_version = mod::g_instance->get_minecraft_version();

	if (this->classes.find(name) != this->classes.end()) {
		log_warn(xor ("Class [%s] already registered"), name);
		return;
	}

	// Get class
	jclass cls = env_classfinder ? env->FindClass(try_list[0].cls) : nullptr;

	for (const auto& try_class : try_list) {
		for (const auto& mc_version : try_class.mc_version) {
			if (strstr(current_version, mc_version)) {
				cls = sdk::g_wrapper->find_class(this->env, try_class.cls, this->m_class_loader);

				// If the first call fails, try again with replaced slashes
				if (!cls) {
					const auto class_name = utils::string::replace_all(try_class.cls, xor ("."), xor ("/"));
					cls = sdk::g_wrapper->find_class(this->env, class_name.c_str(), this->m_class_loader);
				}
			}
		}

		// If a class was found, exit the loop
		if (cls) break;
	}

	// If no class was found, attempt to find a default class based on the current Minecraft version
	if (!cls) {
		for (const auto& vanilla : vanilla_mappings) {
			if (strstr(current_version, vanilla.mc_version)) {
				cls = sdk::g_wrapper->find_class(this->env, vanilla.name, this->m_class_loader);
			}
		}
	}

	// If still no class was found, log an error and return
	if (!cls) {
		log_err(xor ("Failed to find class %s"), name);
		return;
	}

	// Create new class
	auto c_class = std::make_shared<sdk::c_class>(name, cls, env);
	
	// Add class to map
	this->classes.insert(std::make_pair(name, c_class));
	
	log_ok(xor ("Registered class [%s] - %p"), name, cls);
}

void sdk::c_class::register_method(const char* method_name, s_method method) {
	const auto current_version = mod::g_instance->get_minecraft_version();

	std::string parameters(xor ("()"));
	std::string return_type(xor(""));
	std::string signature;

	parameters.clear();
	parameters += xor ("(");

	// test case
	std::reverse(method.sig.begin(), method.sig.end());
	
	for (auto& sig : method.sig) {
		if (std::find(sig.mc_version.begin(), sig.mc_version.end(), current_version) != sig.mc_version.end()) {			
			const auto sig_params = wrapper::jni::extract_params(sig.mtd);
			auto sig_return_type = wrapper::jni::extract_return_type(sig.mtd);
			return_type = sig_return_type;

			for (const auto& param : sig_params) {
				if (param.length() == 1) {
					parameters += param;
					continue;
				}
				if (param.find("/minecraft") != std::string::npos) {
					// class to str
					const auto splitted = utils::string::explode(param, '/');
					const auto& cls_name = splitted.back();
					parameters += "L" + sdk::g_wrapper->class_to_string(env, g_mapper->classes[cls_name.c_str()]->cls) + ";"; // concatenation using + operator
					continue;
				}
				parameters += "L" + param + ";"; // concatenation using + operator
			}
			
			if (sig_return_type.find("/minecraft") != std::string::npos) {
				// class to str
				const auto splitted = utils::string::explode(sig_return_type, '/');
				std::string cls_name = splitted.back();
				cls_name.pop_back();
					
				const std::string array_prefix = "[";
				const auto is_array = sig_return_type.compare(0, array_prefix.size(), array_prefix) == 0;

				const auto cls_to_str = sdk::g_wrapper->class_to_string(env, g_mapper->classes[cls_name.c_str()]->cls);

				return_type = utils::string::replace_all((is_array ? "[L" : "L") + cls_to_str + ";", ".", "/"); // concatenation using + operator
			}
			break;
		}
	}
	parameters += xor (")");

	signature = parameters + return_type;

	// get our method id
	jmethodID mid = nullptr;
	
	for (const auto& try_class : method.try_list) {
		for (const auto& mc_version : try_class.mc_version) {
			if (strstr(current_version, mc_version.c_str())) {
				mid = this->env->GetStaticMethodID(this->cls, try_class.mtd.c_str(), signature.c_str());
				
				if (!mid) {
					this->env->GetMethodID(this->cls, try_class.mtd.c_str(), signature.c_str());
				}
			}
		}

		// If a class was found, exit the loop
		if (mid) break;
	}

	if (!mid) {
		for (const auto& vanilla : method.vanilla_mappings) {
			if (strstr(current_version, vanilla.first.c_str())) {
				mid = this->env->GetMethodID(this->cls, vanilla.second.c_str(), signature.c_str());
				if (!mid)
					mid = this->env->GetStaticMethodID(this->cls, vanilla.second.c_str(), signature.c_str()); {
				}
			}
		}
	}

	if (!mid){
		log_err(xor ("Failed to register method [%s] | SIGNATURE = %s - %p"), method_name, signature.c_str(), mid);
		return;
	}

	log_ok(xor ("Registered method [%s] | SIGNATURE = %s - %p"), method_name, signature.c_str(), mid);

	methods.insert(std::make_pair(method_name, mid));
}

std::unique_ptr<sdk::c_mapper> sdk::g_mapper;
