#include "minecraft.hpp"

sdk::c_minecraft::c_minecraft(JNIEnv* env) {
	this->env = env;

	// init mapping
	// TODO: uncouple this from minecraft constructor
	sdk::g_mapper->register_class(
		("Minecraft"), // name
		{
			{ xor ("net.minecraft.client.Minecraft"), { xor ("1.7.10"),xor ("1.8.9")}, true}
		},
		xor ("bao"), // 1.7.10
		xor ("ave") // 1.8.9
	);

	const auto& minecraft_class = sdk::g_mapper->classes["Minecraft"];

	minecraft_class->register_method(
		xor ("getMinecraft"),
		{
			{}, // parameters
			sdk::g_wrapper->class_to_string(env, minecraft_class->get_class()), // signature
		{
			{
				xor("getMinecraft"),
				{ xor ("1.7.10"),xor ("1.8.9") }
			},
			{
				xor ("func_71410_x"), // forge
				{ xor ("1.7.10"), xor("1.8.9")}
			}
		},
			xor ("B"), // 1.7.10
			xor ("A"), // 1.8.9
			true // yes, it's static
		}
	);

	//this->mc_ = this->env->CallStaticObjectMethod(minecraft_class->get_class(),
	//	sdk::g_mapper->classes["Minecraft"]->methods["getMinecraft"]);
}

void sdk::c_minecraft::destroy() {
	this->env->DeleteLocalRef(this->mc_);
}

jobject sdk::c_minecraft::get() const {
	return this->mc_;
}