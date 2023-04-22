#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::gui::inventory {
	class CGuiChest {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CGuiChest(JNIEnv* env);
		CGuiChest(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CGuiChest();

	};
}
