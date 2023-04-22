#pragma once
#include "includes.hpp"

namespace sdk::net::minecraft::client::renderer {
	class CThreadDownloadImageData {
	private:
		JNIEnv* env;
		jobject instance = nullptr;
	public:
		CThreadDownloadImageData(JNIEnv* env);
		CThreadDownloadImageData(JNIEnv* env, jobject instance);
		jobject getInstance() { return this->instance; }

		~CThreadDownloadImageData();

		void setBufferedImage(jobject);
	};
}
