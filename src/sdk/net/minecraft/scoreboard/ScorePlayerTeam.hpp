#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::scoreboard {
	class CScorePlayerTeam {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CScorePlayerTeam(JNIEnv* env);
		CScorePlayerTeam(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CScorePlayerTeam();

	};
}
