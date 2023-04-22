#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer::texture {
	class CITextureObject {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CITextureObject(JNIEnv* env);
		CITextureObject(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CITextureObject();

	};
}
