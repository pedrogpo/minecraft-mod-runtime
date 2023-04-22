#include "NetworkManager.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::CNetworkManager::CNetworkManager(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::CNetworkManager::CNetworkManager(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::CNetworkManager::~CNetworkManager() {
	this->env->DeleteLocalRef(this->instance);
}

