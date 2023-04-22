#include "RenderManager.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::entity::CRenderManager::CRenderManager(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRenderManager::CRenderManager(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRenderManager::~CRenderManager() {
	this->env->DeleteLocalRef(this->instance);
}

