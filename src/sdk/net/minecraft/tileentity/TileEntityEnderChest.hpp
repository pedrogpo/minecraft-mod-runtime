#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::tileentity {
	class CTileEntityEnderChest {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTileEntityEnderChest(JNIEnv* env);
		CTileEntityEnderChest(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTileEntityEnderChest();

	};
}
