#include "GuiContainer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::gui::inventory::CGuiContainer::CGuiContainer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::gui::inventory::CGuiContainer::CGuiContainer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::gui::inventory::CGuiContainer::~CGuiContainer() {
	this->env->DeleteLocalRef(this->instance);
}

