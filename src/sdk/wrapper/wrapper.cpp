#include "wrapper.hpp"

jobject sdk::c_wrapper::get_class_loader(JNIEnv* env) {
	jobject class_loader = nullptr;
	
	const auto jvm_threads_arr = wrapper::jni::get_all_threads(env);

	if (!jvm_threads_arr) {
		log_debug("Failed to get all threads");
		return class_loader;
	}

	const auto threads_count = env->GetArrayLength(jvm_threads_arr);

	const jclass thread_class = env->FindClass(xor ("java/lang/Thread"));
	const auto get_name = env->GetMethodID(thread_class, xor ("getName"), xor ("()Ljava/lang/String;"));
	const auto ctx_cls_loader = env->GetFieldID(thread_class, xor ("contextClassLoader"), xor ("Ljava/lang/ClassLoader;"));

	for (auto i = 0; i < threads_count; i++) {
		const auto thread = env->GetObjectArrayElement(jvm_threads_arr, i);
		const auto thread_name = reinterpret_cast<jstring>(env->CallObjectMethod(thread, get_name));
		const auto thread_str = env->GetStringUTFChars(thread_name, nullptr);

		if (strstr(thread_str, xor ("Client thread"))) {
			class_loader = env->GetObjectField(thread, ctx_cls_loader);
		}

		env->ReleaseStringUTFChars(thread_name, thread_str);
		env->DeleteLocalRef(thread_name);
		env->DeleteLocalRef(thread);
		if (class_loader != nullptr) break;
	}

	env->DeleteLocalRef(jvm_threads_arr);
	env->DeleteLocalRef(thread_class);

	return class_loader;
}

jclass sdk::c_wrapper::find_class(JNIEnv* env, const char* cls, jobject class_loader) {
	if (!class_loader) {
		return env->FindClass(cls);
	}

	const auto java_class_cls = env->FindClass(xor ("java/lang/Class"));
	if (!java_class_cls) {
		log_err("Failed to find java/lang/Class");
		return nullptr;
	}
	
	const auto for_name_mid = env->GetStaticMethodID(java_class_cls, xor ("forName"), xor ("(Ljava/lang/String;ZLjava/lang/ClassLoader;)Ljava/lang/Class;"));
	if (!for_name_mid) {
		log_err("Failed to find forName method");
		return nullptr;
	}
	
	const auto name = env->NewStringUTF(cls);

	if (!name) {
		env->DeleteLocalRef(java_class_cls);
		log_err("Failed to create jstring");
		return nullptr;
	}
	
	const auto class_ = static_cast<jclass>(env->CallStaticObjectMethod(java_class_cls, for_name_mid, name, false, class_loader));
	
	env->DeleteLocalRef(name);
	env->DeleteLocalRef(java_class_cls);

	if (class_ == nullptr) {
		return env->FindClass(cls);
	}

	return class_;
}

bool sdk::c_wrapper::exception(JNIEnv* env) {
#ifdef _DEBUG
	if (env->ExceptionCheck())
	{
		const auto exc = env->ExceptionOccurred();
		const auto object_cls = env->FindClass("java/lang/Object");
		const auto to_string = env->GetMethodID(object_cls, "toString", "()Ljava/lang/String;");
		const auto s = reinterpret_cast<jstring>(env->CallObjectMethod(exc, to_string));
		env->DeleteLocalRef(object_cls);
		auto utf = env->GetStringUTFChars(s, nullptr);
		env->ReleaseStringUTFChars(s, utf);
		env->DeleteLocalRef(s);
		if (strstr(utf, xor ("NullPointerException")) != nullptr) return false;
		else log_warn(xor ("ERROR: %s"), utf);
		utf = nullptr;
		env->ExceptionClear();
		return true;
	}
#endif // _debug
	return false;
}
