#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/inventory/Slot.hpp"

namespace sdk::net::minecraft::inventory {
	class CContainer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CContainer(JNIEnv* env);
		CContainer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CContainer();

		std::shared_ptr<sdk::net::minecraft::inventory::CSlot> getSlot(jint);
	};
}
