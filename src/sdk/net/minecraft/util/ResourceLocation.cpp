#include "ResourceLocation.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CResourceLocation::CResourceLocation(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CResourceLocation::CResourceLocation(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CResourceLocation::~CResourceLocation() {
	this->env->DeleteLocalRef(this->instance);
}

