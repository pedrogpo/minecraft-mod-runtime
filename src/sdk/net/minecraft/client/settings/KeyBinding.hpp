#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::settings {
	class CKeyBinding {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CKeyBinding(JNIEnv* env);
		CKeyBinding(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CKeyBinding();

		void unpressKey();
	};
}
