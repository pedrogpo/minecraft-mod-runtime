#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::entity::monster {
	class CEntityMob {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntityMob(JNIEnv* env);
		CEntityMob(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntityMob();

	};
}
