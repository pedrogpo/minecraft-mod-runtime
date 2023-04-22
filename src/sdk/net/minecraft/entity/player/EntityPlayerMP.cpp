#include "EntityPlayerMP.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::player::CEntityPlayerMP::CEntityPlayerMP(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::player::CEntityPlayerMP::CEntityPlayerMP(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::player::CEntityPlayerMP::~CEntityPlayerMP() {
	this->env->DeleteLocalRef(this->instance);
}

