#include "ItemEgg.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemEgg::CItemEgg(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemEgg::CItemEgg(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemEgg::~CItemEgg() {
	this->env->DeleteLocalRef(this->instance);
}

