#pragma once
#include "../mod/mod.hpp"
#include "../utils/string/string.hpp"
#include "../utils/game/game.hpp"
#include "wrapper/wrapper.hpp"

namespace sdk {
	struct s_try_class {
		const char* cls;
		std::vector<const char*> mc_version;
		bool replace_slashs = false;
	};

	struct s_try_method {
		const char* mtd;
		std::vector<const char*> mc_version;
	};

	struct s_method
	{
		// method parameters
		std::vector<std::string> params;
		// method signature
		std::string sig;
		// method try list
		std::vector<sdk::s_try_method> try_list;
		// method name for 1.7.10
		const char* v1_7;
		// method name for 1.8.9
		const char* v1_8;
		bool is_static, is_java, is_array = false;
	};


	class c_class {
	private:
		const char* class_name;

		jclass cls;

		JNIEnv* env;
	public:
		// a map of all registered methods of this class.
		std::map<const char*, jmethodID> methods;

		// a map of all registered fields of this class.
		std::map<const char*, jfieldID> fields;

		c_class(const char* t, jclass c, JNIEnv* env) {
			this->class_name = t;
			this->cls = c;
			this->env = env;
		}

		~c_class() {
			this->methods.clear();
			this->fields.clear();
		}

		// register a new method 
		void register_method(const char* method_name, s_method method);

		// get class
		jclass get_class() { return this->cls; }
	};

	class c_mapper {
	private:
		// Minecraft classloader
		jobject m_class_loader = nullptr;

		// current env
		JNIEnv* env;
	public:
		c_mapper(JNIEnv* env) : env(env) {	}
		
		~c_mapper() { };

		bool init();

		void destroy();

		const auto get_class_loader() {
			return this->m_class_loader;
		}

		const auto get_env() {
			return this->env;
		}

		// jclass register method
		void register_class(const char* name, std::vector<s_try_class> try_list, const char* v1_7 = nullptr, const char* v1_8 = nullptr, bool env_classfinder = false);
		
		// a map of all registered classes
		std::map<const char*, std::shared_ptr<c_class>> classes;
	};

	extern std::unique_ptr<c_mapper> g_mapper;
}