#include "C0APacketAnimation.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::client::CC0APacketAnimation::CC0APacketAnimation(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC0APacketAnimation::CC0APacketAnimation(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::client::CC0APacketAnimation::~CC0APacketAnimation() {
	this->env->DeleteLocalRef(this->instance);
}

