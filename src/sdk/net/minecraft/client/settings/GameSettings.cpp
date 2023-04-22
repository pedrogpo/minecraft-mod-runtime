#include "GameSettings.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::settings::CGameSettings::CGameSettings(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::settings::CGameSettings::CGameSettings(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::settings::CGameSettings::~CGameSettings() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Lnet/minecraft/client/settings/KeyBinding;
*/
jboolean sdk::net::minecraft::client::settings::CGameSettings::isKeyDown(jobject param0) {
	return this->env->CallBooleanMethod(this->instance, sdk::g_mapper->classes["GameSettings"]->methods["isKeyDown"], param0);
}
	
