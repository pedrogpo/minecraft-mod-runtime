#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CMovingObjectPosition$MovingObjectType {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CMovingObjectPosition$MovingObjectType(JNIEnv* env);
		CMovingObjectPosition$MovingObjectType(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CMovingObjectPosition$MovingObjectType();

	};
}
