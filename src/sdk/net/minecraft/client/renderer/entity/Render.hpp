#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer::entity {
	class CRender {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CRender(JNIEnv* env);
		CRender(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CRender();

	};
}
