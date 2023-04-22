#include "Container.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::inventory::CContainer::CContainer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::inventory::CContainer::CContainer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::inventory::CContainer::~CContainer() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 I
*/
std::shared_ptr<sdk::net::minecraft::inventory::CSlot> sdk::net::minecraft::inventory::CContainer::getSlot(jint param0) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["Container"]->methods["getSlot"], param0);
	return std::make_shared<sdk::net::minecraft::inventory::CSlot>(this->env, obj);
}
	
