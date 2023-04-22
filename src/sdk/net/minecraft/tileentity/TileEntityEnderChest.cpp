#include "TileEntityEnderChest.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::tileentity::CTileEntityEnderChest::CTileEntityEnderChest(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::tileentity::CTileEntityEnderChest::CTileEntityEnderChest(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::tileentity::CTileEntityEnderChest::~CTileEntityEnderChest() {
	this->env->DeleteLocalRef(this->instance);
}

