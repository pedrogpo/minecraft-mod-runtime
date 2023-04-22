#include "RendererLivingEntity.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::entity::CRendererLivingEntity::CRendererLivingEntity(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRendererLivingEntity::CRendererLivingEntity(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRendererLivingEntity::~CRendererLivingEntity() {
	this->env->DeleteLocalRef(this->instance);
}

