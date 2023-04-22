#include "IWorldNameable.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::world::CIWorldNameable::CIWorldNameable(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::world::CIWorldNameable::CIWorldNameable(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::world::CIWorldNameable::~CIWorldNameable() {
	this->env->DeleteLocalRef(this->instance);
}

