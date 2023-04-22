#include "Render.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::entity::CRender::CRender(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRender::CRender(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::entity::CRender::~CRender() {
	this->env->DeleteLocalRef(this->instance);
}

