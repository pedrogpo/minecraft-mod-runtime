#include "ItemPotion.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemPotion::CItemPotion(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemPotion::CItemPotion(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemPotion::~CItemPotion() {
	this->env->DeleteLocalRef(this->instance);
}

