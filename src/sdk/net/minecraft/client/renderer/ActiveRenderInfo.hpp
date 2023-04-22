#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer {
	class CActiveRenderInfo {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CActiveRenderInfo(JNIEnv* env);
		CActiveRenderInfo(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CActiveRenderInfo();

	};
}
