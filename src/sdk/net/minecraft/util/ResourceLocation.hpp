#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CResourceLocation {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CResourceLocation(JNIEnv* env);
		CResourceLocation(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CResourceLocation();

	};
}
