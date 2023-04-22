#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC0BPacketEntityAction {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC0BPacketEntityAction(JNIEnv* env);
		CC0BPacketEntityAction(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC0BPacketEntityAction();

	};
}
