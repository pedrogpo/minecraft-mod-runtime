#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC02PacketUseEntity {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC02PacketUseEntity(JNIEnv* env);
		CC02PacketUseEntity(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC02PacketUseEntity();

	};
}
