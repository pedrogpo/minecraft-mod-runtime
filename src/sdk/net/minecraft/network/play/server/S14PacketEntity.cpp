#include "S14PacketEntity.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS14PacketEntity::CS14PacketEntity(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS14PacketEntity::CS14PacketEntity(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS14PacketEntity::~CS14PacketEntity() {
	this->env->DeleteLocalRef(this->instance);
}

