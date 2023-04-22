#include "Slot.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::inventory::CSlot::CSlot(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::inventory::CSlot::CSlot(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::inventory::CSlot::~CSlot() {
	this->env->DeleteLocalRef(this->instance);
}

std::shared_ptr<sdk::net::minecraft::item::CItemStack> sdk::net::minecraft::inventory::CSlot::getStack() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["Slot"]->methods["getStack"]);
	return std::make_shared<sdk::net::minecraft::item::CItemStack>(this->env, obj);
}
	
jboolean sdk::net::minecraft::inventory::CSlot::getHasStack() {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["Slot"]->methods["getHasStack"]);
}
	
