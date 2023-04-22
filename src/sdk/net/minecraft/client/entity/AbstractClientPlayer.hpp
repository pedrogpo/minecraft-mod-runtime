#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/util/ResourceLocation.hpp"

namespace sdk::net::minecraft::client::entity {
	class CAbstractClientPlayer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CAbstractClientPlayer(JNIEnv* env);
		CAbstractClientPlayer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CAbstractClientPlayer();

		std::shared_ptr<sdk::net::minecraft::util::CResourceLocation> getLocationSkin(jobject);
		std::shared_ptr<sdk::net::minecraft::util::CResourceLocation> getLocationSkin();
	};
}
