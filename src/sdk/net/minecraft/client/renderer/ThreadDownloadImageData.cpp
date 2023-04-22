#include "ThreadDownloadImageData.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::client::renderer::CThreadDownloadImageData::CThreadDownloadImageData(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CThreadDownloadImageData::CThreadDownloadImageData(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::client::renderer::CThreadDownloadImageData::~CThreadDownloadImageData() {
	this->env->DeleteLocalRef(this->instance);
}

/** 
* @param param0 Ljava/awt/image/BufferedImage;
*/
void sdk::net::minecraft::client::renderer::CThreadDownloadImageData::setBufferedImage(jobject param0) {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["ThreadDownloadImageData"]->methods["setBufferedImage"], param0);
}
	
