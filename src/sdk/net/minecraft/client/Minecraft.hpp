#pragma once
#include "includes.hpp"
#include "sdk/net/minecraft/client/network/NetHandlerPlayClient.hpp"
#include "sdk/abstract/fields.hpp"
#include <sdk/mapper.hpp>

namespace sdk::net::minecraft::client {
	class CMinecraft {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CMinecraft(JNIEnv* env);
		CMinecraft(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CMinecraft();

		std::shared_ptr<sdk::net::minecraft::client::network::CNetHandlerPlayClient> getNetHandler();
		std::shared_ptr<sdk::net::minecraft::client::CMinecraft> getMinecraft();

		sdk::CField<bool> f_fullscreen() {
			const auto fid = this->env->GetFieldID(sdk::g_mapper->classes["Minecraft"]->get_class(), "N", "Z");
			return sdk::CField<bool>(this->env, this->instance, fid);
		}
	};
}
