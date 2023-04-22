#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC0APacketAnimation {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC0APacketAnimation(JNIEnv* env);
		CC0APacketAnimation(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC0APacketAnimation();

	};
}
