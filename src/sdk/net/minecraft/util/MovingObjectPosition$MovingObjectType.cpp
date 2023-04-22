#include "MovingObjectPosition$MovingObjectType.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CMovingObjectPosition$MovingObjectType::CMovingObjectPosition$MovingObjectType(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CMovingObjectPosition$MovingObjectType::CMovingObjectPosition$MovingObjectType(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CMovingObjectPosition$MovingObjectType::~CMovingObjectPosition$MovingObjectType() {
	this->env->DeleteLocalRef(this->instance);
}

