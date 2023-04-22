#include "TextureManager.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::texture::CTextureManager::CTextureManager(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::texture::CTextureManager::CTextureManager(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::texture::CTextureManager::~CTextureManager() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/util/ResourceLocation;
*/
void sdk::net::minecraft::client::renderer::texture::CTextureManager::bindTexture(jobject param0) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["TextureManager"]->methods["bindTexture"], param0);
}
	
/** 
* @param param0 Lnet/minecraft/util/ResourceLocation;* @param param1 Lnet/minecraft/client/renderer/texture/ITextureObject;
*/
jboolean sdk::net::minecraft::client::renderer::texture::CTextureManager::loadTexture(jobject param0, jobject param1) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["TextureManager"]->methods["loadTexture"], param0, param1);
}
	
/** 
* @param param0 Lnet/minecraft/util/ResourceLocation;
*/
void sdk::net::minecraft::client::renderer::texture::CTextureManager::deleteTexture(jobject param0) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["TextureManager"]->methods["deleteTexture"], param0);
}
	
