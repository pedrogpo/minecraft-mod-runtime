#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/entity/Entity.hpp"

namespace sdk::net::minecraft::world {
	class CWorld {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CWorld(JNIEnv* env);
		CWorld(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CWorld();

		std::shared_ptr<sdk::net::minecraft::entity::CEntity> getEntityByID(jint);
		jboolean isAirBlock(jint, jint, jint);
		jboolean isAirBlock(jobject);
		jboolean isAirBlock1(jobject);
	};
}
