#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS00PacketKeepAlive {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS00PacketKeepAlive(JNIEnv* env);
		CS00PacketKeepAlive(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS00PacketKeepAlive();

	};
}
