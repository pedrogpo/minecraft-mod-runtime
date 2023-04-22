#include "C02PacketUseEntity.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC02PacketUseEntity::CC02PacketUseEntity(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC02PacketUseEntity::CC02PacketUseEntity(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC02PacketUseEntity::~CC02PacketUseEntity() {
	this->env->DeleteLocalRef(this->instance);
}

