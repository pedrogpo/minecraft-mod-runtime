#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::network::play::client {
	class CC0FPacketConfirmTransaction {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CC0FPacketConfirmTransaction(JNIEnv* env);
		CC0FPacketConfirmTransaction(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CC0FPacketConfirmTransaction();

	};
}
