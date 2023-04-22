#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::entity::player {
	class CEntityPlayer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntityPlayer(JNIEnv* env);
		CEntityPlayer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntityPlayer();

		void closeScreen();
		void attackTargetEntityWithCurrentItem(jobject);
		jint getItemInUseCount();
	};
}
