#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemEgg {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemEgg(JNIEnv* env);
		CItemEgg(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemEgg();

	};
}
