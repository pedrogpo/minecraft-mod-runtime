#include "EntityPlayer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::player::CEntityPlayer::CEntityPlayer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::player::CEntityPlayer::CEntityPlayer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::player::CEntityPlayer::~CEntityPlayer() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/entity/Entity;
*/
void sdk::net::minecraft::entity::player::CEntityPlayer::attackTargetEntityWithCurrentItem(jobject param0) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["EntityPlayer"]->methods["attackTargetEntityWithCurrentItem"], param0);
}
	
jint sdk::net::minecraft::entity::player::CEntityPlayer::getItemInUseCount() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["EntityPlayer"]->methods["getItemInUseCount"]);
}
	
void sdk::net::minecraft::entity::player::CEntityPlayer::closeScreen() {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["EntityPlayer"]->methods["closeScreen"]);
}
	
