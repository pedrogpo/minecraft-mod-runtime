#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CVec3 {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CVec3(JNIEnv* env);
		CVec3(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CVec3();

		std::shared_ptr<sdk::net::minecraft::util::CVec3> addVector(jdouble, jdouble, jdouble);
		jdouble distanceTo(jobject);
	};
}
