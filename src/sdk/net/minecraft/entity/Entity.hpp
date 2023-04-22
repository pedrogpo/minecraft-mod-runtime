#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::entity {
	class CEntity {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntity(JNIEnv* env);
		CEntity(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntity();

		jboolean isSprinting();
		jfloat getCollisionBorderSize();
		jboolean isEntityAlive();
		void setSprinting(jboolean);
		jfloat getDistanceToEntity(jobject);
		jboolean canBeCollidedWith();
		jboolean isSneaking();
		jboolean isInvisible();
	};
}
