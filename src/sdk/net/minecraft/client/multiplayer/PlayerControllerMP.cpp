#include "PlayerControllerMP.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::multiplayer::CPlayerControllerMP::CPlayerControllerMP(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::multiplayer::CPlayerControllerMP::CPlayerControllerMP(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::multiplayer::CPlayerControllerMP::~CPlayerControllerMP() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 I* @param param1 I* @param param2 I* @param param3 I* @param param4 Lnet/minecraft/entity/player/EntityPlayer;
*/
std::shared_ptr<sdk::net::minecraft::item::CItemStack> sdk::net::minecraft::client::multiplayer::CPlayerControllerMP::windowClick(jint param0, jint param1, jint param2, jint param3, jobject param4) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["PlayerControllerMP"]->methods["windowClick"], param0, param1, param2, param3, param4);
	return std::make_shared<sdk::net::minecraft::item::CItemStack>(this->env, obj);
}
	
/** 
* @param param0 I* @param param1 I* @param param2 I* @param param3 Lnet/minecraft/inventory/ClickType;* @param param4 Lnet/minecraft/entity/player/EntityPlayer;
*/
std::shared_ptr<sdk::net::minecraft::item::CItemStack> sdk::net::minecraft::client::multiplayer::CPlayerControllerMP::windowClick(jint param0, jint param1, jint param2, jobject param3, jobject param4) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["PlayerControllerMP"]->methods["windowClick"], param0, param1, param2, param3, param4);
	return std::make_shared<sdk::net::minecraft::item::CItemStack>(this->env, obj);
}
	
/** 
* @param param0 Lnet/minecraft/entity/player/EntityPlayer;* @param param1 Lnet/minecraft/world/World;* @param param2 Lnet/minecraft/item/ItemStack;
*/
jboolean sdk::net::minecraft::client::multiplayer::CPlayerControllerMP::sendUseItem(jobject param0, jobject param1, jobject param2) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["PlayerControllerMP"]->methods["sendUseItem"], param0, param1, param2);
}
	
