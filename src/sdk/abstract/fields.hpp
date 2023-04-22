#pragma once
#include <includes.hpp>
#include <type_traits>
#include <iostream>

namespace sdk {
	typedef struct CUtils {
		template<class T> constexpr static T GetField(JNIEnv* env, _In_ jobject _JavaMirror, jfieldID fid) {		
			if constexpr (std::is_same_v<T, double>) {
				return env->GetDoubleField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, float>) {
				return env->GetFloatField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, long long>) {
				return env->GetLongField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, int>) {
				return env->GetIntField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
				return env->GetByteField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
				return env->GetBooleanField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, char>) {
				return env->GetCharField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, short>) {
				return env->GetShortField(_JavaMirror, fid);
			}
			if constexpr (std::is_same_v<T, jobject>) {
				return env->GetObjectField(_JavaMirror, fid);
			}

			return T();
		}

		template<class T> constexpr static void SetField(JNIEnv* env, jobject _JavaMirror, _In_ jfieldID fid, const T val) {
			if constexpr (std::is_same_v<T, double>) {
				return env->SetDoubleField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, float>) {
				return env->SetFloatField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, long long>) {
				return env->SetLongField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, int>) {
				return env->SetIntField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
				return env->SetByteField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
				return env->SetBooleanField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, char>) {
				return env->SetCharField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, short>) {
				return env->SetShortField(_JavaMirror, fid, val);
			}
			if constexpr (std::is_same_v<T, jobject>) {
				return env->SetObjectField(_JavaMirror, fid, val);
			}
		}

		template<class T> constexpr static T GetStaticField(JNIEnv* env, jclass _JavaClass, _In_ jfieldID fid) {
			if constexpr (std::is_same_v<T, double>) {
				return env->GetStaticDoubleField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, float>) {
				return env->GetStaticFloatField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, long long>) {
				return env->GetStaticLongField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, int>) {
				return env->GetStaticIntField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
				return env->GetStaticByteField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
				return env->GetStaticBooleanField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, char>) {
				return env->GetStaticCharField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, short>) {
				return env->GetStaticShortField(_JavaClass, fid);
			}
			if constexpr (std::is_same_v<T, jobject>) {
				return env->GetStaticObjectField(_JavaClass, fid);
			}

			return T();
		}

		template<class T> constexpr static void SetStaticField(JNIEnv* env, jclass _JavaClass, _In_ jfieldID fid, const T val) {
			if constexpr (std::is_same_v<T, double>) {
				return env->SetStaticDoubleField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, float>) {
				return env->SetStaticFloatField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, long long>) {
				return env->SetStaticLongField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, int>) {
				return env->SetStaticIntField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, byte> || std::is_same_v<T, jbyte>) {
				return env->SetStaticByteField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, bool> || std::is_same_v<T, boolean> || std::is_same_v<T, jboolean>) {
				return env->SetStaticBooleanField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, char>) {
				return env->SetStaticCharField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, short>) {
				return env->SetStaticShortField(_JavaClass, fid, val);
			}
			if constexpr (std::is_same_v<T, jobject>) {
				return env->SetStaticObjectField(_JavaClass, fid, val);
			}
		}

	};
	
	template <typename T> class CField {
	private:
		JNIEnv* env;
		jobject obj;
		jfieldID fid;
	public: 
		CField(JNIEnv* env, jobject obj, jfieldID fid) {
			this->env = env;
			this->obj = obj;
			this->fid = fid;
		}

		void operator=(T value) {
			CUtils::template SetField<T>(this->env, this->obj, this->fid, value);
		}

		operator T() {
			return CUtils::template GetField<T>(this->env, this->obj, this->fid);
		}
	};

	template <typename T> class CStaticField {
	private:
		JNIEnv* env;
		jobject obj;
		jfieldID fid;
	public:
		CStaticField(JNIEnv* env, jobject obj, jfieldID fid) {
			this->env = env;
			this->obj = obj;
			this->fid = fid;
		}

		void operator=(T value) {
			CUtils::template SetStaticField<T>(this->env, this->obj, this->fid, value);
		}

		operator T() {
			return CUtils::template GetStaticField<T>(this->env, this->obj, this->fid);
		}
	};
}