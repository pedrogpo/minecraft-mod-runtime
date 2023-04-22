#include "GuiChest.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::gui::inventory::CGuiChest::CGuiChest(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::gui::inventory::CGuiChest::CGuiChest(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::gui::inventory::CGuiChest::~CGuiChest() {
	this->env->DeleteLocalRef(this->instance);
}

