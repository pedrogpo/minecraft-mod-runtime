#include "Team.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::scoreboard::CTeam::CTeam(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::scoreboard::CTeam::CTeam(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::scoreboard::CTeam::~CTeam() {
	this->env->DeleteLocalRef(this->instance);
}

