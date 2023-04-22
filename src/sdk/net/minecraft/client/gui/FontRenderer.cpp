#include "FontRenderer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::gui::CFontRenderer::CFontRenderer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::gui::CFontRenderer::CFontRenderer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::gui::CFontRenderer::~CFontRenderer() {
	this->env->DeleteLocalRef(this->instance);
}

