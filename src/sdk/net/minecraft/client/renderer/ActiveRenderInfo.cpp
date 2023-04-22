#include "ActiveRenderInfo.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::CActiveRenderInfo::CActiveRenderInfo(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CActiveRenderInfo::CActiveRenderInfo(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CActiveRenderInfo::~CActiveRenderInfo() {
	this->env->DeleteLocalRef(this->instance);
}

