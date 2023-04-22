#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/item/ItemStack.hpp"
#include "sdk/net/minecraft/scoreboard/Team.hpp"

namespace sdk::net::minecraft::entity {
	class CEntityLivingBase  {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CEntityLivingBase(JNIEnv* env);
		CEntityLivingBase(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CEntityLivingBase();

		jfloat getSwingProgress(jfloat);
		std::shared_ptr<sdk::net::minecraft::item::CItemStack> getHeldItem();
		std::shared_ptr<sdk::net::minecraft::item::CItemStack> getHeldItem(jobject);
		std::shared_ptr<sdk::net::minecraft::item::CItemStack> getCurrentArmor(jint);
		jboolean isOnSameTeam(jobject);
		jfloat getHealth();
		std::shared_ptr<sdk::net::minecraft::scoreboard::CTeam> getTeam();
	};
}
