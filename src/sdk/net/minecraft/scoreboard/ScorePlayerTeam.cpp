#include "ScorePlayerTeam.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::scoreboard::CScorePlayerTeam::CScorePlayerTeam(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::scoreboard::CScorePlayerTeam::CScorePlayerTeam(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::scoreboard::CScorePlayerTeam::~CScorePlayerTeam() {
	this->env->DeleteLocalRef(this->instance);
}

