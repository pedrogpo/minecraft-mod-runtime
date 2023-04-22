#include "S32PacketConfirmTransaction.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS32PacketConfirmTransaction::CS32PacketConfirmTransaction(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS32PacketConfirmTransaction::CS32PacketConfirmTransaction(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS32PacketConfirmTransaction::~CS32PacketConfirmTransaction() {
	this->env->DeleteLocalRef(this->instance);
}

