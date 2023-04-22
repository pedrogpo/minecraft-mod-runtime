#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::scoreboard {
	class CTeam$EnumVisible {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTeam$EnumVisible(JNIEnv* env);
		CTeam$EnumVisible(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTeam$EnumVisible();

	};
}
