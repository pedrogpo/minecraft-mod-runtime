#include "EntityMob.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::monster::CEntityMob::CEntityMob(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::monster::CEntityMob::CEntityMob(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::monster::CEntityMob::~CEntityMob() {
	this->env->DeleteLocalRef(this->instance);
}

