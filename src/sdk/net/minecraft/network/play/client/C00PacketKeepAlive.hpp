#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC00PacketKeepAlive {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC00PacketKeepAlive(JNIEnv* env);
		CC00PacketKeepAlive(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC00PacketKeepAlive();

	};
}
