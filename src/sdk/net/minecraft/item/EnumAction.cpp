#include "EnumAction.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::item::CEnumAction::CEnumAction(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::item::CEnumAction::CEnumAction(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::item::CEnumAction::~CEnumAction() {
	this->env->DeleteLocalRef(this->instance);
}

