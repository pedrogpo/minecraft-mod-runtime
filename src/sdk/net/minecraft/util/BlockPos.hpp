#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CBlockPos {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CBlockPos(JNIEnv* env);
		CBlockPos(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CBlockPos();

	};
}
