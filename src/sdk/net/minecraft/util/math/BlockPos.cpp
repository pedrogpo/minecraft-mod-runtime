#include "BlockPos.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::math::CBlockPos::CBlockPos(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::math::CBlockPos::CBlockPos(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::math::CBlockPos::~CBlockPos() {
	this->env->DeleteLocalRef(this->instance);
}

