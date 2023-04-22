#include "KeyBinding.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::settings::CKeyBinding::CKeyBinding(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::settings::CKeyBinding::CKeyBinding(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::settings::CKeyBinding::~CKeyBinding() {
	this->env->DeleteLocalRef(this->instance);
}

void sdk::net::minecraft::client::settings::CKeyBinding::unpressKey() {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["KeyBinding"]->methods["unpressKey"]);
}
	
