#include "AxisAlignedBB.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CAxisAlignedBB::CAxisAlignedBB(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CAxisAlignedBB::CAxisAlignedBB(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CAxisAlignedBB::~CAxisAlignedBB() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 D* @param param1 D* @param param2 D
*/
std::shared_ptr<sdk::net::minecraft::util::CAxisAlignedBB> sdk::net::minecraft::util::CAxisAlignedBB::expand(jdouble param0, jdouble param1, jdouble param2) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["AxisAlignedBB"]->methods["expand"], param0, param1, param2);
	return std::make_shared<sdk::net::minecraft::util::CAxisAlignedBB>(this->env, obj);
}
	
/** 
* @param param0 Lnet/minecraft/util/Vec3;
*/
jboolean sdk::net::minecraft::util::CAxisAlignedBB::isVecInside(jobject param0) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["AxisAlignedBB"]->methods["isVecInside"], param0);
}
	
