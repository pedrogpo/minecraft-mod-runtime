#include "C0BPacketEntityAction.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC0BPacketEntityAction::CC0BPacketEntityAction(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC0BPacketEntityAction::CC0BPacketEntityAction(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC0BPacketEntityAction::~CC0BPacketEntityAction() {
	this->env->DeleteLocalRef(this->instance);
}

