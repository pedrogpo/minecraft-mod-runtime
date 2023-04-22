#include "MouseHelper.hpp"
#include <sdk/mapper.hpp>

sdk::net::minecraft::util::CMouseHelper::CMouseHelper(JNIEnv* env) {
	this->env = env;
}

sdk::net::minecraft::util::CMouseHelper::CMouseHelper(JNIEnv* env, jobject instance) : instance(instance) {
	this->env = env;
}

sdk::net::minecraft::util::CMouseHelper::~CMouseHelper() {
	this->env->DeleteLocalRef(this->instance);
}

void sdk::net::minecraft::util::CMouseHelper::grabMouseCursor() {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["MouseHelper"]->methods["grabMouseCursor"]);
}
	
void sdk::net::minecraft::util::CMouseHelper::ungrabMouseCursor() {
	return this->env->CallVoidMethod(this->instance, sdk::g_mapper->classes["MouseHelper"]->methods["ungrabMouseCursor"]);
}
	
