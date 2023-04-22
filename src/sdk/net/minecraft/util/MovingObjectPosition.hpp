#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CMovingObjectPosition {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CMovingObjectPosition(JNIEnv* env);
		CMovingObjectPosition(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CMovingObjectPosition();

	};
}
