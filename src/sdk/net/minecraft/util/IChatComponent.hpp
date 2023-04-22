#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CIChatComponent {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CIChatComponent(JNIEnv* env);
		CIChatComponent(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CIChatComponent();

	};
}
