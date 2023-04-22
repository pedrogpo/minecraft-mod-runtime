#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::gui {
	class CGuiScreen {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CGuiScreen(JNIEnv* env);
		CGuiScreen(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CGuiScreen();

	};
}
