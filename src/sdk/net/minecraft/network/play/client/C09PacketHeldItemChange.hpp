#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC09PacketHeldItemChange {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC09PacketHeldItemChange(JNIEnv* env);
		CC09PacketHeldItemChange(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC09PacketHeldItemChange();

	};
}
