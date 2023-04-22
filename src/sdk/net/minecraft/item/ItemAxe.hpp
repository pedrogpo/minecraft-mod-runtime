#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemAxe {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemAxe(JNIEnv* env);
		CItemAxe(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemAxe();

	};
}
