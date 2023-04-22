#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer::texture {
	class CTextureManager {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTextureManager(JNIEnv* env);
		CTextureManager(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTextureManager();

		void bindTexture(jobject);
		jboolean loadTexture(jobject, jobject);
		void deleteTexture(jobject);
	};
}
