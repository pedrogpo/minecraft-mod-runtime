#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/entity/Entity.hpp"

namespace sdk::net::minecraft::client::multiplayer {
	class CWorldClient {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CWorldClient(JNIEnv* env);
		CWorldClient(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CWorldClient();

		std::shared_ptr<sdk::net::minecraft::entity::CEntity> removeEntityFromWorld(jint);
	};
}
