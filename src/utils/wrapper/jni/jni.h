#pragma once
#include "../../../includes.hpp"
#include <sstream>

namespace wrapper {
	namespace jni {
		[[nodiscard]] inline bool get_created_java_vms(JavaVM** jvm) {
			const auto jvm_handle = LI_FN(GetModuleHandleA).safe_cached()(xor ("jvm.dll"));

			if (!jvm_handle) {
				log_debug(xor ("Failed to get jvm.dll handle"));
				return false;
			}

			typedef long(_stdcall* JNI_GetCreatedJavaVMs_t)(JavaVM**, long, long*);

			const auto get_created_java_vms = reinterpret_cast<JNI_GetCreatedJavaVMs_t>(LI_FN(GetProcAddress).safe_cached()(jvm_handle, xor  ("JNI_GetCreatedJavaVMs")));

			if (!get_created_java_vms) {
				log_debug(xor ("Failed to get JNI_GetCreatedJavaVMs"));
				return false;
			}

			const auto vms_status = get_created_java_vms(&*jvm, 1, nullptr);

			if (vms_status != JNI_OK) {
				log_debug(xor("Failed to get created java vms"));
				return false;
			}

			return true;
		}

		[[nodiscard]] inline jobjectArray get_all_threads(JNIEnv* env) {
			const auto jvm_handle = LI_FN(GetModuleHandleA).safe_cached()(xor ("jvm.dll"));

			if (!jvm_handle) {
				log_debug(xor ("Failed to get jvm.dll handle"));
				return nullptr;
			}

			typedef jobjectArray(JNICALL* JVM_GetAllThreads)(JNIEnv*, jclass);

			const auto get_all_threads = reinterpret_cast<JVM_GetAllThreads>(LI_FN(GetProcAddress).safe_cached()(jvm_handle, xor ("JVM_GetAllThreads")));

			if (!get_all_threads) {
				log_debug(xor ("Failed to get JVM_GetAllThreads"));
				return nullptr;
			}

			return get_all_threads(env, nullptr);
		}

        [[nodiscard]] inline std::vector<std::string> extract_params(const std::string& signature) {
            std::vector<std::string> params_list;

            // Find the start and end index of the parameter type string
            size_t start_index = signature.find("(") + 1;
            size_t end_index = signature.find(")", start_index);

            if (start_index == std::string::npos || end_index == std::string::npos) {
                // Invalid signature
                return params_list;
            }

            // Extract the parameter type string
            std::string params_str = signature.substr(start_index, end_index - start_index);

            // Loop over the parameter type string
            for (size_t i = 0; i < params_str.size(); i++) {
                char c = params_str[i];
                if (c == 'L') {
                    // Extract the class name from the parameter type
                    size_t class_start_index = i + 1;
                    size_t class_end_index = params_str.find(";", class_start_index);
                    if (class_end_index == std::string::npos) {
                        // Invalid parameter type
                        return params_list;
                    }
                    std::string class_name = params_str.substr(class_start_index, class_end_index - class_start_index);
                    params_list.push_back(class_name);
                    i = class_end_index;
                }
                else if (c == '[') {
                    // Array type
                    size_t array_end_index = i + 1;
                    while (params_str[array_end_index] == '[') {
                        array_end_index++;
                    }
                    if (params_str[array_end_index] == 'L') {
                        // Object array type
                        size_t class_start_index = array_end_index + 1;
                        size_t class_end_index = params_str.find(";", class_start_index);
                        if (class_end_index == std::string::npos) {
                            // Invalid parameter type
                            return params_list;
                        }
                        std::string class_name = params_str.substr(class_start_index, class_end_index - class_start_index);
                        // Replace '/' with '.' in the class name
                        std::replace(class_name.begin(), class_name.end(), '/', '.');
                        params_list.push_back(class_name + "[]");
                        i = class_end_index;
                    }
                    else {
                        // Primitive array type
                        char type = params_str[array_end_index];
                        params_list.push_back(std::string(1, type) + "[]");
                        i = array_end_index;
                    }
                }
                else {
                    // Primitive type
                    params_list.push_back(std::string(1, c));
                }
            }

            return params_list;
        }

        [[nodiscard]] inline std::string extract_return_type(const std::string& signature) {
            std::istringstream signature_stream(signature);
            std::string token;

            // Skip parameters
            while (std::getline(signature_stream, token, '(')) {
                // Stop when we find the return type
                if (std::getline(signature_stream, token, ')')) {
                    break;
                }
            }

            // Parse return type
            std::getline(signature_stream, token);
            return token;
        }
	}
}