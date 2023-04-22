#include "TileEntity.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::tileentity::CTileEntity::CTileEntity(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::tileentity::CTileEntity::CTileEntity(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::tileentity::CTileEntity::~CTileEntity() {
	this->env->DeleteLocalRef(this->instance);
}

std::shared_ptr<sdk::net::minecraft::util::CBlockPos> sdk::net::minecraft::tileentity::CTileEntity::getPos() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["TileEntity"]->methods["getPos"]);
	return std::make_shared<sdk::net::minecraft::util::CBlockPos>(this->env, obj);
}
	
std::shared_ptr<sdk::net::minecraft::util::math::CBlockPos> sdk::net::minecraft::tileentity::CTileEntity::getPos1() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["TileEntity"]->methods["getPos"]);
	return std::make_shared<sdk::net::minecraft::util::math::CBlockPos>(this->env, obj);
}
	
