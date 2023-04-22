#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::gui::inventory {
	class CGuiContainer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CGuiContainer(JNIEnv* env);
		CGuiContainer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CGuiContainer();

	};
}
