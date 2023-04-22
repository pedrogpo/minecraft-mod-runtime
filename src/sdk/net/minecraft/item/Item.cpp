#include "Item.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CItem::CItem(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CItem::CItem(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CItem::~CItem() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/item/Item;
*/
jint sdk::net::minecraft::item::CItem::getIdFromItem(jobject param0) {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["Item"]->methods["getIdFromItem"], param0);
}
	
