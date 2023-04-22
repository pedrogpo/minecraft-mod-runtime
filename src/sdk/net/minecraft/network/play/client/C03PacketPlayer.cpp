#include "C03PacketPlayer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC03PacketPlayer::CC03PacketPlayer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC03PacketPlayer::CC03PacketPlayer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC03PacketPlayer::~CC03PacketPlayer() {
	this->env->DeleteLocalRef(this->instance);
}

