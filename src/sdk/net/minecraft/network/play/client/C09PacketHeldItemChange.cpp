#include "C09PacketHeldItemChange.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC09PacketHeldItemChange::CC09PacketHeldItemChange(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC09PacketHeldItemChange::CC09PacketHeldItemChange(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC09PacketHeldItemChange::~CC09PacketHeldItemChange() {
	this->env->DeleteLocalRef(this->instance);
}

