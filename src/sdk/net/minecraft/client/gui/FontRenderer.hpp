#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::gui {
	class CFontRenderer {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CFontRenderer(JNIEnv* env);
		CFontRenderer(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CFontRenderer();

	};
}
