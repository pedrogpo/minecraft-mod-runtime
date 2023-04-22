#include "IInventory.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::inventory::CIInventory::CIInventory(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::inventory::CIInventory::CIInventory(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::inventory::CIInventory::~CIInventory() {
	this->env->DeleteLocalRef(this->instance);
}

jint sdk::net::minecraft::inventory::CIInventory::getSizeInventory() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["IInventory"]->methods["getSizeInventory"]);
}
	
