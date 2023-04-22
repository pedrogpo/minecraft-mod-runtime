#include "C0FPacketConfirmTransaction.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC0FPacketConfirmTransaction::CC0FPacketConfirmTransaction(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC0FPacketConfirmTransaction::CC0FPacketConfirmTransaction(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC0FPacketConfirmTransaction::~CC0FPacketConfirmTransaction() {
	this->env->DeleteLocalRef(this->instance);
}

