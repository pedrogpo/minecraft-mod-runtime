#include "Entity.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::entity::CEntity::CEntity(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::entity::CEntity::CEntity(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::entity::CEntity::~CEntity() {
	this->env->DeleteLocalRef(this->instance);
}

jboolean sdk::net::minecraft::entity::CEntity::canBeCollidedWith() {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["canBeCollidedWith"]);
}
	
jboolean sdk::net::minecraft::entity::CEntity::isSneaking() {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["isSneaking"]);
}
	
jboolean sdk::net::minecraft::entity::CEntity::isInvisible() {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["isInvisible"]);
}
	
jboolean sdk::net::minecraft::entity::CEntity::isSprinting() {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["isSprinting"]);
}
	
jfloat sdk::net::minecraft::entity::CEntity::getCollisionBorderSize() {
	return this->env->CallFloatMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["getCollisionBorderSize"]);
}
	
jboolean sdk::net::minecraft::entity::CEntity::isEntityAlive() {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["isEntityAlive"]);
}
	
/** 
* @param param0 Z
*/
void sdk::net::minecraft::entity::CEntity::setSprinting(jboolean param0) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["setSprinting"], param0);
}
	
/** 
* @param param0 Lnet/minecraft/entity/Entity;
*/
jfloat sdk::net::minecraft::entity::CEntity::getDistanceToEntity(jobject param0) {
	return this->env->CallFloatMethod(this->instance, sdk::g_mapper->classes["Entity"]->methods["getDistanceToEntity"], param0);
}
	
