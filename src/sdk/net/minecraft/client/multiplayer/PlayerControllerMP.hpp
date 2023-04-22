#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/item/ItemStack.hpp"

namespace sdk::net::minecraft::client::multiplayer {
	class CPlayerControllerMP {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CPlayerControllerMP(JNIEnv* env);
		CPlayerControllerMP(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CPlayerControllerMP();

		std::shared_ptr<sdk::net::minecraft::item::CItemStack> windowClick(jint, jint, jint, jobject, jobject);
		std::shared_ptr<sdk::net::minecraft::item::CItemStack> windowClick(jint, jint, jint, jint, jobject);
		jboolean sendUseItem(jobject, jobject, jobject);
	};
}
