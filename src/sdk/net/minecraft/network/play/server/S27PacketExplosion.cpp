#include "S27PacketExplosion.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS27PacketExplosion::CS27PacketExplosion(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS27PacketExplosion::CS27PacketExplosion(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS27PacketExplosion::~CS27PacketExplosion() {
	this->env->DeleteLocalRef(this->instance);
}

