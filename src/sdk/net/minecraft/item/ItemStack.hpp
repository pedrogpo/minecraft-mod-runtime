#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/item/EnumAction.hpp"

namespace sdk::net::minecraft::item {
	class CItemStack {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItemStack(JNIEnv* env);
		CItemStack(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItemStack();

		jint getMaxDamage();
		jint getMetadata();
		std::shared_ptr<sdk::net::minecraft::item::CEnumAction> getItemUseAction();
	};
}
