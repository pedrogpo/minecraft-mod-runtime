#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CAxisAlignedBB {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CAxisAlignedBB(JNIEnv* env);
		CAxisAlignedBB(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CAxisAlignedBB();

		jboolean isVecInside(jobject);
		std::shared_ptr<sdk::net::minecraft::util::CAxisAlignedBB> expand(jdouble, jdouble, jdouble);
	};
}
