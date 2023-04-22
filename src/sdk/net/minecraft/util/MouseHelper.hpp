#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::util {
	class CMouseHelper {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CMouseHelper(JNIEnv* env);
		CMouseHelper(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CMouseHelper();

		void grabMouseCursor();
		void ungrabMouseCursor();
	};
}
