#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CVec3i {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CVec3i(JNIEnv* env);
		CVec3i(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CVec3i();

		jint getY();
		jint getZ();
		jint getX();
	};
}
