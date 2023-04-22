#include "RenderItem.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::entity::CRenderItem::CRenderItem(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRenderItem::CRenderItem(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRenderItem::~CRenderItem() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/client/gui/FontRenderer;* @param param1 Lnet/minecraft/client/renderer/texture/TextureManager;* @param param2 Lnet/minecraft/item/ItemStack;* @param param3 I* @param param4 I
*/
void sdk::net::minecraft::client::renderer::entity::CRenderItem::renderItemAndEffectIntoGUI(jobject param0, jobject param1, jobject param2, jint param3, jint param4) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["RenderItem"]->methods["renderItemAndEffectIntoGUI"], param0, param1, param2, param3, param4);
}
	
/** 
* @param param0 Lnet/minecraft/item/ItemStack;* @param param1 I* @param param2 I
*/
void sdk::net::minecraft::client::renderer::entity::CRenderItem::renderItemAndEffectIntoGUI(jobject param0, jint param1, jint param2) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["RenderItem"]->methods["renderItemAndEffectIntoGUI"], param0, param1, param2);
}
	
