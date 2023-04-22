#include "ItemAxe.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemAxe::CItemAxe(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemAxe::CItemAxe(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemAxe::~CItemAxe() {
	this->env->DeleteLocalRef(this->instance);
}

