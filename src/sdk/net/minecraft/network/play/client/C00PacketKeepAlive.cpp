#include "C00PacketKeepAlive.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC00PacketKeepAlive::CC00PacketKeepAlive(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC00PacketKeepAlive::CC00PacketKeepAlive(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC00PacketKeepAlive::~CC00PacketKeepAlive() {
	this->env->DeleteLocalRef(this->instance);
}

