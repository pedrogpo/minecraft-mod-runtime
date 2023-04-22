#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::server {
	class CS32PacketConfirmTransaction {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CS32PacketConfirmTransaction(JNIEnv* env);
		CS32PacketConfirmTransaction(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CS32PacketConfirmTransaction();

	};
}
