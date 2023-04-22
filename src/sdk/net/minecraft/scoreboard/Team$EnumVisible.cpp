#include "Team$EnumVisible.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::scoreboard::CTeam$EnumVisible::CTeam$EnumVisible(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::scoreboard::CTeam$EnumVisible::CTeam$EnumVisible(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::scoreboard::CTeam$EnumVisible::~CTeam$EnumVisible() {
	this->env->DeleteLocalRef(this->instance);
}

