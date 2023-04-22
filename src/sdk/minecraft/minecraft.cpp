#include "minecraft.hpp"
#include "../mappings/classes.hpp"
#include "../mappings/methods.hpp"

sdk::c_minecraft::c_minecraft(JNIEnv* env) {
	this->env = env;
	

	//const auto& mc_class = sdk::g_mapper->classes["Minecraft"];

	//mc_class->register_method("getMinecraft",
	//	{
	//		{{"lol", {"1.8.9", "1.7.10"}}, {"a", {"1.7.10", "1.12.2"}}}, // parameters
	//		{
	//			{sdk::g_wrapper->class_to_string(env, mc_class->get_class()), {"1.7.10", "1.8.9", "1.12.2"}}
	//		}, // signature
	//	{
	//		{
	//			xor ("getMinecraft"),
	//			{ xor ("1.7.10"),xor ("1.8.9") }
	//		},
	//		{
	//			xor ("func_71410_x"), // forge
	//			{ xor ("1.7.10"),xor ("1.8.9")}
	//		}
	//	},
	//		{
	//			{ xor ("1.7.10"),xor ("B") },
	//			{ xor ("1.8.9"),xor ("A")},
	//		}
	//	}
	//);

	//this->mc_ = this->env->CallStaticObjectMethod(mc_class->get_class(), mc_class->methods["getMinecraft"]);
}

void sdk::c_minecraft::destroy() {
	//this->env->DeleteLocalRef(this->mc_);
}

jobject sdk::c_minecraft::get() const {
	return this->mc_;
}