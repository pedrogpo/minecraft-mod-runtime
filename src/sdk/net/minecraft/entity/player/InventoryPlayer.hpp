#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::entity::player {
	class CInventoryPlayer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CInventoryPlayer(JNIEnv* env);
		CInventoryPlayer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CInventoryPlayer();

	};
}
