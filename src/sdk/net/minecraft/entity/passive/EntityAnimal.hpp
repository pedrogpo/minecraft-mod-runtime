#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::entity::passive {
	class CEntityAnimal {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntityAnimal(JNIEnv* env);
		CEntityAnimal(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntityAnimal();

	};
}
