#include "IChatComponent.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CIChatComponent::CIChatComponent(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CIChatComponent::CIChatComponent(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CIChatComponent::~CIChatComponent() {
	this->env->DeleteLocalRef(this->instance);
}

