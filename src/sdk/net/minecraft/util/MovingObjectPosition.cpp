#include "MovingObjectPosition.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CMovingObjectPosition::CMovingObjectPosition(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CMovingObjectPosition::CMovingObjectPosition(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CMovingObjectPosition::~CMovingObjectPosition() {
	this->env->DeleteLocalRef(this->instance);
}

