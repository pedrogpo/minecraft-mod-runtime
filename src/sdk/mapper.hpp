#pragma once
#include "../mod/mod.hpp"
#include "../utils/string/string.hpp"
#include "../utils/game/game.hpp"
#include "wrapper/wrapper.hpp"
#include "mappings/classes.hpp"
#include "mappings/methods.hpp"

struct compare_str {
	bool operator()(const char* a, const char* b) const {
		return std::strcmp(a, b) < 0;
	}
};

namespace sdk {
	class c_class {
	private:
		const char* class_name;

		jclass cls;

		JNIEnv* env;
	public:
		// a map of all registered methods of this class.
		std::map<const char*, jmethodID, compare_str> methods;

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
		void register_class(const char* name, std::vector<s_try_class> try_list, std::vector<s_vanilla_mapping>, bool env_classfinder = false);
		
		// a map of all registered classes
		std::map<const char*, std::shared_ptr<c_class>, compare_str> classes;
	};

	extern std::unique_ptr<c_mapper> g_mapper;
}