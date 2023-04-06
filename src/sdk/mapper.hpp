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

	class c_class {
	private:
		const char* class_name;

		jclass cls;
	public:
		// a map of all registered methods of this class.
		std::map<const char*, jmethodID> methods;

		// a map of all registered fields of this class.
		std::map<const char*, jfieldID> fields;

		c_class(const char* t, jclass c) {
			this->class_name = t;
			this->cls = c;
		}
		
		~c_class() {
			this->methods.clear();
			this->fields.clear(); 
		}

		// get class
		jclass get_class() { return this->cls; }
	};

	class c_mapper {
	private:
		// Minecraft version support
		const	std::vector<const char*> m_versions = { "1.7.10", "1.8.8", "1.8.9" };

		// Minecraft classloader
		jobject m_class_loader = nullptr;
		
		// current env
		JNIEnv* env;

		// class register method
		void register_class(const char* name, std::vector<s_try_class> try_list, const char* v1_7 = nullptr, const char* v1_8 = nullptr, bool env_classfinder = false);

		// a map of all registered classes
		std::map<const char*, std::shared_ptr<c_class>> classes;

		// mc version
		const char* current_version = nullptr;
	public:
		c_mapper(JNIEnv* env) : env(env) {	}
		
		~c_mapper() { };
		
		bool init();
		
		void destroy();

		const char* get_minecraft_version(const char*);

		// Getters
		const auto get_versions() {
			return this->m_versions;
		}

		const auto get_class_loader() {
			return this->m_class_loader;
		}
	};

	extern std::unique_ptr<c_mapper> g_mapper;
}