#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemArmor {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemArmor(JNIEnv* env);
		CItemArmor(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemArmor();

	};
}
