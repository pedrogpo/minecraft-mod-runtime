#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer::entity {
	class CRendererLivingEntity {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CRendererLivingEntity(JNIEnv* env);
		CRendererLivingEntity(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CRendererLivingEntity();

	};
}
