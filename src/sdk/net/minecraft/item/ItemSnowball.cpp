#include "ItemSnowball.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemSnowball::CItemSnowball(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemSnowball::CItemSnowball(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemSnowball::~CItemSnowball() {
	this->env->DeleteLocalRef(this->instance);
}

