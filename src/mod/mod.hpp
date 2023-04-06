#pragma once
#include "../includes.hpp"
#include "../utils/wrapper/jni/jni.h"
#include "../sdk/mapper.hpp"

namespace mod {
	class c_mod {
	private:
		JNIEnv* env;
		JavaVM* jvm;

		// Minecraft version support
		const	std::vector<const char*> m_versions = { "1.7.10", "1.8.8", "1.8.9" };

		// Current minecraft version
		const char* m_version = nullptr;
	public:
		c_mod() = default;
		~c_mod() = default;
		
		const auto get_env() {
			return this->env;
		}

		const auto get_jvm() {
			return this->jvm;
		}

		// initialize the cheat
		void initialize();

		// shutdown the cheat
		void shutdown();

		// attach the cheat to the java vm
		bool attach();

		// get minecraft version
		bool get_version();

		// get minecraft version
		const auto get_minecraft_version() {
			return this->m_version;
		}
	};
	
	inline auto g_instance = std::make_unique<c_mod>();
}