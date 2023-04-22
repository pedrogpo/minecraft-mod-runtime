#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::settings {
	class CGameSettings {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CGameSettings(JNIEnv* env);
		CGameSettings(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CGameSettings();

		jboolean isKeyDown(jobject);
	};
}
