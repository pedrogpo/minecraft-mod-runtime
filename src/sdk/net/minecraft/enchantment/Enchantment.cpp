#include "Enchantment.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::enchantment::CEnchantment::CEnchantment(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::enchantment::CEnchantment::CEnchantment(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::enchantment::CEnchantment::~CEnchantment() {
	this->env->DeleteLocalRef(this->instance);
}

