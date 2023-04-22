#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItemBlock {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemBlock(JNIEnv* env);
		CItemBlock(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemBlock();

	};
}
