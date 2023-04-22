#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::scoreboard {
	class CTeam {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTeam(JNIEnv* env);
		CTeam(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTeam();

	};
}
