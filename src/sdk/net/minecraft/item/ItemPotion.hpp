#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemPotion {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemPotion(JNIEnv* env);
		CItemPotion(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemPotion();

	};
}
