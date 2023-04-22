#include "Vec3.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CVec3::CVec3(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CVec3::CVec3(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CVec3::~CVec3() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/util/Vec3;
*/
jdouble sdk::net::minecraft::util::CVec3::distanceTo(jobject param0) {
	return this->env->CallDoubleMethod(this->instance, sdk::g_mapper->classes["Vec3"]->methods["distanceTo"], param0);
}
	
/** 
* @param param0 D* @param param1 D* @param param2 D
*/
std::shared_ptr<sdk::net::minecraft::util::CVec3> sdk::net::minecraft::util::CVec3::addVector(jdouble param0, jdouble param1, jdouble param2) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["Vec3"]->methods["addVector"], param0, param1, param2);
	return std::make_shared<sdk::net::minecraft::util::CVec3>(this->env, obj);
}
	
