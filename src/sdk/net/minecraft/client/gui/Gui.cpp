#include "Gui.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::gui::CGui::CGui(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::gui::CGui::CGui(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::gui::CGui::~CGui() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 I* @param param1 I* @param param2 F* @param param3 F* @param param4 I* @param param5 I* @param param6 I* @param param7 I* @param param8 F* @param param9 F
*/
void sdk::net::minecraft::client::gui::CGui::drawScaledCustomSizeModalRect(jint param0, jint param1, jfloat param2, jfloat param3, jint param4, jint param5, jint param6, jint param7, jfloat param8, jfloat param9) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["Gui"]->methods["drawScaledCustomSizeModalRect"], param0, param1, param2, param3, param4, param5, param6, param7, param8, param9);
}
	
