#include "WorldClient.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::multiplayer::CWorldClient::CWorldClient(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::multiplayer::CWorldClient::CWorldClient(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::multiplayer::CWorldClient::~CWorldClient() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 I
*/
std::shared_ptr<sdk::net::minecraft::entity::CEntity> sdk::net::minecraft::client::multiplayer::CWorldClient::removeEntityFromWorld(jint param0) {
	const auto obj = this->env->CallObjectMethod(this->instance, sdk::g_mapper->classes["WorldClient"]->methods["removeEntityFromWorld"], param0);
	return std::make_shared<sdk::net::minecraft::entity::CEntity>(this->env, obj);
}
	
