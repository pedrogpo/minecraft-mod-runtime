#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer {
	class CIImageBuffer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CIImageBuffer(JNIEnv* env);
		CIImageBuffer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CIImageBuffer();

	};
}
