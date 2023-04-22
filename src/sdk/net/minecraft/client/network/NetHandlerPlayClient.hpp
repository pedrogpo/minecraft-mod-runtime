#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::network {
	class CNetHandlerPlayClient {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CNetHandlerPlayClient(JNIEnv* env);
		CNetHandlerPlayClient(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CNetHandlerPlayClient();

	};
}
