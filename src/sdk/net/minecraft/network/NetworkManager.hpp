#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network {
	class CNetworkManager {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CNetworkManager(JNIEnv* env);
		CNetworkManager(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CNetworkManager();

	};
}
