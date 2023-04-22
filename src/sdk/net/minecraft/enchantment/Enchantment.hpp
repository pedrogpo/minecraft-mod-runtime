#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::enchantment {
	class CEnchantment {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEnchantment(JNIEnv* env);
		CEnchantment(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEnchantment();

	};
}
