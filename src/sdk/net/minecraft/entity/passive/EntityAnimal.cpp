#include "EntityAnimal.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::passive::CEntityAnimal::CEntityAnimal(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::passive::CEntityAnimal::CEntityAnimal(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::passive::CEntityAnimal::~CEntityAnimal() {
	this->env->DeleteLocalRef(this->instance);
}

