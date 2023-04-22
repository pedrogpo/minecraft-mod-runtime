#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::world {
	class CIWorldNameable {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CIWorldNameable(JNIEnv* env);
		CIWorldNameable(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CIWorldNameable();

	};
}
