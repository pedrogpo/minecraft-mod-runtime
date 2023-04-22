#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer {
	class CRenderItem {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CRenderItem(JNIEnv* env);
		CRenderItem(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CRenderItem();

		void renderItemAndEffectIntoGUI(jobject, jobject, jint, jint);
		void renderItemAndEffectIntoGUI(jobject, jint, jint);
	};
}
