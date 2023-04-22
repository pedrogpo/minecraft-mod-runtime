#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::item {
	class CItem {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CItem(JNIEnv* env);
		CItem(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CItem();

		jint getIdFromItem(jobject);
	};
}
