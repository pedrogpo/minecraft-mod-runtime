#include "ItemSword.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemSword::CItemSword(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemSword::CItemSword(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemSword::~CItemSword() {
	this->env->DeleteLocalRef(this->instance);
}

