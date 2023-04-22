#include "Vec3i.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::math::CVec3i::CVec3i(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::math::CVec3i::CVec3i(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::math::CVec3i::~CVec3i() {
	this->env->DeleteLocalRef(this->instance);
}

jint sdk::net::minecraft::util::math::CVec3i::getX() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["Vec3i"]->methods["getX"]);
}
	
jint sdk::net::minecraft::util::math::CVec3i::getY() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["Vec3i"]->methods["getY"]);
}
	
jint sdk::net::minecraft::util::math::CVec3i::getZ() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["Vec3i"]->methods["getZ"]);
}
	
