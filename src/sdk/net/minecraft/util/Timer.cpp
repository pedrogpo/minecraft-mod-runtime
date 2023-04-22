#include "Timer.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CTimer::CTimer(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CTimer::CTimer(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CTimer::~CTimer() {
	this->env->DeleteLocalRef(this->instance);
}

