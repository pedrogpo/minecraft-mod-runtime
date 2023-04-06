#pragma once
#include "../mapper.hpp"

namespace sdk {
	class c_wrapper {
	private:
	public:
		c_wrapper() = default;
		
		~c_wrapper() = default;

		jobject get_class_loader(JNIEnv* env);

		jclass find_class(JNIEnv* env, const char* cls, jobject class_loader = nullptr);

		bool exception(JNIEnv* env);
	};

	inline auto g_wrapper = std::make_unique<c_wrapper>();
}