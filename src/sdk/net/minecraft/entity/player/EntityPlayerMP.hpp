#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::entity::player {
	class CEntityPlayerMP {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntityPlayerMP(JNIEnv* env);
		CEntityPlayerMP(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntityPlayerMP();

	};
}
