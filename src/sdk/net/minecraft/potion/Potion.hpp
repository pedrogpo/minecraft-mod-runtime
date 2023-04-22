#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::potion {
	class CPotion {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CPotion(JNIEnv* env);
		CPotion(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CPotion();

	};
}
