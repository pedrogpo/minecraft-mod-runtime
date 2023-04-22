#include "Potion.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::potion::CPotion::CPotion(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::potion::CPotion::CPotion(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::potion::CPotion::~CPotion() {
	this->env->DeleteLocalRef(this->instance);
}

