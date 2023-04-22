#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS19PacketEntityHeadLook {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS19PacketEntityHeadLook(JNIEnv* env);
		CS19PacketEntityHeadLook(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS19PacketEntityHeadLook();

	};
}
