#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS14PacketEntity {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS14PacketEntity(JNIEnv* env);
		CS14PacketEntity(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS14PacketEntity();

	};
}
