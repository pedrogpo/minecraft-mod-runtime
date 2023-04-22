#include "ItemBlock.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemBlock::CItemBlock(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemBlock::CItemBlock(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemBlock::~CItemBlock() {
	this->env->DeleteLocalRef(this->instance);
}

