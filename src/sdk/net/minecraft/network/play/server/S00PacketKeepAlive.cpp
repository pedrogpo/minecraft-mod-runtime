#include "S00PacketKeepAlive.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS00PacketKeepAlive::CS00PacketKeepAlive(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS00PacketKeepAlive::CS00PacketKeepAlive(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS00PacketKeepAlive::~CS00PacketKeepAlive() {
	this->env->DeleteLocalRef(this->instance);
}

