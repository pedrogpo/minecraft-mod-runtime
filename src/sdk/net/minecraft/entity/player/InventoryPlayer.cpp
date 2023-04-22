#include "InventoryPlayer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::player::CInventoryPlayer::CInventoryPlayer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::player::CInventoryPlayer::CInventoryPlayer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::player::CInventoryPlayer::~CInventoryPlayer() {
	this->env->DeleteLocalRef(this->instance);
}

