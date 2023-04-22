#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::tileentity {
	class CTileEntityChest {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CTileEntityChest(JNIEnv* env);
		CTileEntityChest(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CTileEntityChest();

	};
}
