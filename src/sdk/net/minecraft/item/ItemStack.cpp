#include "ItemStack.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItemStack::CItemStack(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItemStack::CItemStack(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItemStack::~CItemStack() {
	this->env->DeleteLocalRef(this->instance);
}

jint sdk::net::minecraft::item::CItemStack::getMetadata() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["ItemStack"]->methods["getMetadata"]);
}
	
std::shared_ptr<sdk::net::minecraft::item::CEnumAction> sdk::net::minecraft::item::CItemStack::getItemUseAction() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["ItemStack"]->methods["getItemUseAction"]);
	return std::make_shared<sdk::net::minecraft::item::CEnumAction>(this->env, obj);
}
	
jint sdk::net::minecraft::item::CItemStack::getMaxDamage() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["ItemStack"]->methods["getMaxDamage"]);
}
	
