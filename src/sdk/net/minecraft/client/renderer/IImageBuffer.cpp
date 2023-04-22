#include "IImageBuffer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::CIImageBuffer::CIImageBuffer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CIImageBuffer::CIImageBuffer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CIImageBuffer::~CIImageBuffer() {
	this->env->DeleteLocalRef(this->instance);
}

