#include "TileEntityChest.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::tileentity::CTileEntityChest::CTileEntityChest(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::tileentity::CTileEntityChest::CTileEntityChest(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::tileentity::CTileEntityChest::~CTileEntityChest() {
	this->env->DeleteLocalRef(this->instance);
}

