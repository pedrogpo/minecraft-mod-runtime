#include "EntityPlayerSP.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::entity::CEntityPlayerSP::CEntityPlayerSP(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::entity::CEntityPlayerSP::CEntityPlayerSP(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::entity::CEntityPlayerSP::~CEntityPlayerSP() {
	this->env->DeleteLocalRef(this->instance);
}

