#include "World.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::world::CWorld::CWorld(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::world::CWorld::CWorld(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::world::CWorld::~CWorld() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 I* @param param1 I* @param param2 I
*/
jboolean sdk::net::minecraft::world::CWorld::isAirBlock(jint param0, jint param1, jint param2) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["World"]->methods["isAirBlock"], param0, param1, param2);
}
	
/** 
* @param param0 Lnet/minecraft/util/BlockPos;
*/
jboolean sdk::net::minecraft::world::CWorld::isAirBlock(jobject param0) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["World"]->methods["isAirBlock"], param0);
}
	
/** 
* @param param0 Lnet/minecraft/util/math/BlockPos;
*/
jboolean sdk::net::minecraft::world::CWorld::isAirBlock1(jobject param0) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["World"]->methods["isAirBlock"], param0);
}
	
/** 
* @param param0 I
*/
std::shared_ptr<sdk::net::minecraft::entity::CEntity> sdk::net::minecraft::world::CWorld::getEntityByID(jint param0) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["World"]->methods["getEntityByID"], param0);
	return std::make_shared<sdk::net::minecraft::entity::CEntity>(this->env, obj);
}
	
