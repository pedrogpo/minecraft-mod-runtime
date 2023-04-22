#include "ITextureObject.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::texture::CITextureObject::CITextureObject(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::texture::CITextureObject::CITextureObject(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::texture::CITextureObject::~CITextureObject() {
	this->env->DeleteLocalRef(this->instance);
}

