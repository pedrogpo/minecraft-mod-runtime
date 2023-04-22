#include "EnchantmentHelper.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::enchantment::CEnchantmentHelper::CEnchantmentHelper(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::enchantment::CEnchantmentHelper::CEnchantmentHelper(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::enchantment::CEnchantmentHelper::~CEnchantmentHelper() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 I* @param param1 Lnet/minecraft/item/ItemStack;
*/
jint sdk::net::minecraft::enchantment::CEnchantmentHelper::getEnchantmentLevel(jint param0, jobject param1) {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["EnchantmentHelper"]->methods["getEnchantmentLevel"], param0, param1);
}
	
/** 
* @param param0 Lnet/minecraft/enchantment/Enchantment;* @param param1 Lnet/minecraft/item/ItemStack;
*/
jint sdk::net::minecraft::enchantment::CEnchantmentHelper::getEnchantmentLevel(jobject param0, jobject param1) {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["EnchantmentHelper"]->methods["getEnchantmentLevel"], param0, param1);
}
	
