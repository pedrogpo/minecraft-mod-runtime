#include "ItemArmor.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemArmor::CItemArmor(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemArmor::CItemArmor(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemArmor::~CItemArmor() {
	this->env->DeleteLocalRef(this->instance);
}

