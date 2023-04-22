#include "S19PacketEntityHeadLook.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS19PacketEntityHeadLook::CS19PacketEntityHeadLook(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS19PacketEntityHeadLook::CS19PacketEntityHeadLook(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS19PacketEntityHeadLook::~CS19PacketEntityHeadLook() {
	this->env->DeleteLocalRef(this->instance);
}

