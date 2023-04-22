#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemSword {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemSword(JNIEnv* env);
		CItemSword(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemSword();

	};
}
