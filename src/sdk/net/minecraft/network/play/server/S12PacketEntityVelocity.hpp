#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS12PacketEntityVelocity {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS12PacketEntityVelocity(JNIEnv* env);
		CS12PacketEntityVelocity(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS12PacketEntityVelocity();

	};
}
