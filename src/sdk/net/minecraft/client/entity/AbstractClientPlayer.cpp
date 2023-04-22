#include "AbstractClientPlayer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::entity::CAbstractClientPlayer::CAbstractClientPlayer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::entity::CAbstractClientPlayer::CAbstractClientPlayer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::entity::CAbstractClientPlayer::~CAbstractClientPlayer() {
	this->env->DeleteLocalRef(this->instance);
}

std::shared_ptr<sdk::net::minecraft::util::CResourceLocation> sdk::net::minecraft::client::entity::CAbstractClientPlayer::getLocationSkin() {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["AbstractClientPlayer"]->methods["getLocationSkin"]);
	return std::make_shared<sdk::net::minecraft::util::CResourceLocation>(this->env, obj);
}
	
/** 
* @param param0 Ljava/lang/String;
*/
std::shared_ptr<sdk::net::minecraft::util::CResourceLocation> sdk::net::minecraft::client::entity::CAbstractClientPlayer::getLocationSkin(jobject param0) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["AbstractClientPlayer"]->methods["getLocationSkin"], param0);
	return std::make_shared<sdk::net::minecraft::util::CResourceLocation>(this->env, obj);
}
	
