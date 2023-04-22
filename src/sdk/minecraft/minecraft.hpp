#pragma once
#include "../../../includes.hpp"
#include "../mapper.hpp"

template <typename T>
std::shared_ptr<T> create_shared() {
	return std::make_shared<T>();
}


namespace sdk {
	class c_minecraft
	{
	private:
		// it's object
		jobject mc_ = nullptr;

		JNIEnv* env;
	public:
		c_minecraft(JNIEnv* env);

		// destroy it's instance
		void destroy();

		// getter
		jobject get() const;
	};

	inline std::unique_ptr<c_minecraft> g_minecraft;
}