#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS18PacketEntityTeleport {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS18PacketEntityTeleport(JNIEnv* env);
		CS18PacketEntityTeleport(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS18PacketEntityTeleport();

		jint getEntityId();
	};
}
