#include "S18PacketEntityTeleport.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::network::play::server::CS18PacketEntityTeleport::CS18PacketEntityTeleport(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS18PacketEntityTeleport::CS18PacketEntityTeleport(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::network::play::server::CS18PacketEntityTeleport::~CS18PacketEntityTeleport() {
	this->env->DeleteLocalRef(this->instance);
}

jint sdk::net::minecraft::network::play::server::CS18PacketEntityTeleport::getEntityId() {
	return this->env->CallIntMethod(this->instance, sdk::g_mapper->classes["S18PacketEntityTeleport"]->methods["getEntityId"]);
}
	
