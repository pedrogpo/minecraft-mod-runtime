#include "S12PacketEntityVelocity.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS12PacketEntityVelocity::CS12PacketEntityVelocity(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS12PacketEntityVelocity::CS12PacketEntityVelocity(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS12PacketEntityVelocity::~CS12PacketEntityVelocity() {
	this->env->DeleteLocalRef(this->instance);
}

