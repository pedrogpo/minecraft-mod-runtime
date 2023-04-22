#include "RenderItem.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::CRenderItem::CRenderItem(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CRenderItem::CRenderItem(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CRenderItem::~CRenderItem() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/entity/EntityLivingBase;* @param param1 Lnet/minecraft/item/ItemStack;* @param param2 I* @param param3 I
*/
void sdk::net::minecraft::client::renderer::CRenderItem::renderItemAndEffectIntoGUI(jobject param0, jobject param1, jint param2, jint param3) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["RenderItem"]->methods["renderItemAndEffectIntoGUI"], param0, param1, param2, param3);
}
	
/** 
* @param param0 Lnet/minecraft/item/ItemStack;* @param param1 I* @param param2 I
*/
void sdk::net::minecraft::client::renderer::CRenderItem::renderItemAndEffectIntoGUI(jobject param0, jint param1, jint param2) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["RenderItem"]->methods["renderItemAndEffectIntoGUI"], param0, param1, param2);
}
	
