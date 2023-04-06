#pragma once
#include "../includes.hpp"
#include "../utils/wrapper/jni/jni.h"
#include "../sdk/mapper.hpp"

namespace mod {
	class c_mod {
	private:
		JNIEnv* env;
		JavaVM* jvm;
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
	};
	
	inline auto g_instance = std::make_unique<c_mod>();
}