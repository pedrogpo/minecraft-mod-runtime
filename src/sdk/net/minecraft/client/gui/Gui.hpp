#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::gui {
	class CGui {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CGui(JNIEnv* env);
		CGui(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CGui();

		void drawScaledCustomSizeModalRect(jint, jint, jfloat, jfloat, jint, jint, jint, jint, jfloat, jfloat);
	};
}
