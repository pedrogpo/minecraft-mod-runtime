#include "GuiScreen.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::gui::CGuiScreen::CGuiScreen(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::gui::CGuiScreen::CGuiScreen(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::gui::CGuiScreen::~CGuiScreen() {
	this->env->DeleteLocalRef(this->instance);
}

