#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CEnumAction {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEnumAction(JNIEnv* env);
		CEnumAction(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEnumAction();

	};
}
