#include "GuiInventory.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::gui::inventory::CGuiInventory::CGuiInventory(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::gui::inventory::CGuiInventory::CGuiInventory(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::gui::inventory::CGuiInventory::~CGuiInventory() {
	this->env->DeleteLocalRef(this->instance);
}

