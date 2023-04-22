#include "NetHandlerPlayClient.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::network::CNetHandlerPlayClient::CNetHandlerPlayClient(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::network::CNetHandlerPlayClient::CNetHandlerPlayClient(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::network::CNetHandlerPlayClient::~CNetHandlerPlayClient() {
	this->env->DeleteLocalRef(this->instance);
}

