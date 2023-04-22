#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CTimer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTimer(JNIEnv* env);
		CTimer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTimer();

	};
}
