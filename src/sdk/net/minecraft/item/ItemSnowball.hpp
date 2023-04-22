#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemSnowball {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemSnowball(JNIEnv* env);
		CItemSnowball(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemSnowball();

	};
}
