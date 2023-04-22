#include "Minecraft.hpp"

sdk::net::minecraft::client::CMinecraft::CMinecraft(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::CMinecraft::CMinecraft(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::CMinecraft::~CMinecraft() {
	this->env->DeleteLocalRef(this->instance);
}

std::shared_ptr<sdk::net::minecraft::client::network::CNetHandlerPlayClient> sdk::net::minecraft::client::CMinecraft::getNetHandler() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["Minecraft"]->methods["getNetHandler"]);
	return std::make_shared<sdk::net::minecraft::client::network::CNetHandlerPlayClient>(this->env, obj);
}
	
std::shared_ptr<sdk::net::minecraft::client::CMinecraft> sdk::net::minecraft::client::CMinecraft::getMinecraft() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["Minecraft"]->methods["getMinecraft"]);
	return std::make_shared<sdk::net::minecraft::client::CMinecraft>(this->env, obj);
}

