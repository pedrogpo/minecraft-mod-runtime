#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::entity {
	class CEntityPlayerSP {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntityPlayerSP(JNIEnv* env);
		CEntityPlayerSP(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntityPlayerSP();

	};
}
