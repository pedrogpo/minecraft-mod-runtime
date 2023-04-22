#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::inventory {
	class CIInventory {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CIInventory(JNIEnv* env);
		CIInventory(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CIInventory();

		jint getSizeInventory();
	};
}
