#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/item/ItemStack.hpp"

namespace sdk::net::minecraft::inventory {
	class CSlot {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CSlot(JNIEnv* env);
		CSlot(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CSlot();

		jboolean getHasStack();
		std::shared_ptr<sdk::net::minecraft::item::CItemStack> getStack();
	};
}
