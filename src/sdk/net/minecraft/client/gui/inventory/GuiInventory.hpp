#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::gui::inventory {
	class CGuiInventory {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CGuiInventory(JNIEnv* env);
		CGuiInventory(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CGuiInventory();

	};
}
