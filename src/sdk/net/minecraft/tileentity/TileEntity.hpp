#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/util/BlockPos.hpp"
#include "sdk/net/minecraft/util/math/BlockPos.hpp"

namespace sdk::net::minecraft::tileentity {
	class CTileEntity {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTileEntity(JNIEnv* env);
		CTileEntity(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTileEntity();

		std::shared_ptr<sdk::net::minecraft::util::CBlockPos> getPos();
		std::shared_ptr<sdk::net::minecraft::util::math::CBlockPos> getPos1();
	};
}
