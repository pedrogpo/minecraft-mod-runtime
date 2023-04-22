#include "EntityLivingBase.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::CEntityLivingBase::CEntityLivingBase(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::CEntityLivingBase::CEntityLivingBase(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::CEntityLivingBase::~CEntityLivingBase() {
	this->env->DeleteLocalRef(this->instance);
}

std::shared_ptr<sdk::net::minecraft::item::CItemStack> sdk::net::minecraft::entity::CEntityLivingBase::getHeldItem() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["getHeldItem"]);
	return std::make_shared<sdk::net::minecraft::item::CItemStack>(this->env, obj);
}
	
/** 
* @param param0 Lnet/minecraft/util/EnumHand;
*/
std::shared_ptr<sdk::net::minecraft::item::CItemStack> sdk::net::minecraft::entity::CEntityLivingBase::getHeldItem(jobject param0) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["getHeldItem"], param0);
	return std::make_shared<sdk::net::minecraft::item::CItemStack>(this->env, obj);
}
	
/** 
* @param param0 I
*/
std::shared_ptr<sdk::net::minecraft::item::CItemStack> sdk::net::minecraft::entity::CEntityLivingBase::getCurrentArmor(jint param0) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["getCurrentArmor"], param0);
	return std::make_shared<sdk::net::minecraft::item::CItemStack>(this->env, obj);
}
	
/** 
* @param param0 Lnet/minecraft/entity/EntityLivingBase;
*/
jboolean sdk::net::minecraft::entity::CEntityLivingBase::isOnSameTeam(jobject param0) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["isOnSameTeam"], param0);
}
	
jfloat sdk::net::minecraft::entity::CEntityLivingBase::getHealth() {
	return this->env->CallFloatMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["getHealth"]);
}
	
std::shared_ptr<sdk::net::minecraft::scoreboard::CTeam> sdk::net::minecraft::entity::CEntityLivingBase::getTeam() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["getTeam"]);
	return std::make_shared<sdk::net::minecraft::scoreboard::CTeam>(this->env, obj);
}
	
/** 
* @param param0 F
*/
jfloat sdk::net::minecraft::entity::CEntityLivingBase::getSwingProgress(jfloat param0) {
	return this->env->CallFloatMethod(this->instance, sdk::g_mapper->classes["EntityLivingBase"]->methods["getSwingProgress"], param0);
}
	
