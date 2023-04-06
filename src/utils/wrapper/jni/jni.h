#pragma once
#include "../../../includes.hpp"

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
	}
}