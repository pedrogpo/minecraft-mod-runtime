#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer::entity {
	class CRenderManager {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CRenderManager(JNIEnv* env);
		CRenderManager(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CRenderManager();

	};
}
