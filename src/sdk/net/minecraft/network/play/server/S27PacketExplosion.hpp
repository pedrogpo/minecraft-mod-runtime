#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS27PacketExplosion {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS27PacketExplosion(JNIEnv* env);
		CS27PacketExplosion(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS27PacketExplosion();

	};
}
