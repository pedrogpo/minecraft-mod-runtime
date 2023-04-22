#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC03PacketPlayer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC03PacketPlayer(JNIEnv* env);
		CC03PacketPlayer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC03PacketPlayer();

	};
}
