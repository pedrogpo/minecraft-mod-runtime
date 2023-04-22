#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::enchantment {
	class CEnchantmentHelper {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEnchantmentHelper(JNIEnv* env);
		CEnchantmentHelper(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEnchantmentHelper();

		jint getEnchantmentLevel(jint, jobject);
		jint getEnchantmentLevel(jobject, jobject);
	};
}
