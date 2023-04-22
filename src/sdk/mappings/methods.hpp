#pragma once
#include <string>
#include <map>
#include <vector>
#include "../../lib/xorstr/xorstring.h"

struct s_try_method {
    std::string mtd;
    std::vector<std::string> mc_version;
};

struct s_method
{
    // method signature
    std::vector<s_try_method> sig;
    // method try list
    std::vector<s_try_method> try_list;
    std::vector<std::pair<std::string, std::string>> vanilla_mappings;
    bool is_java, is_array = false;
};

const std::map<std::string, std::map<std::string, s_method>> mappings_methods = {
	{"AbstractClientPlayer", {
		{"getLocationSkin", {
			{
				s_try_method{"(Ljava/lang/String;)Lnet/minecraft/util/ResourceLocation;", {"1.7.10","1.8.9","1.12.2"}},
				s_try_method{"()Lnet/minecraft/util/ResourceLocation;", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_110311_f", {"1.7.10","1.8.9","1.12.2"}},
				s_try_method{"func_110306_p", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","c"},
				{"1.7.10","r"},
				{"1.8.9","c"},
				{"1.8.9","i"},
				{"1.12.2","e"},
				{"1.12.2","o"},
			},
		}},
	}},
	{"ResourceLocation", {
	}},
	{"TileEntity", {
		{"getPos", {
			{
				s_try_method{"()Lnet/minecraft/util/BlockPos;", {"1.8.9"}},
				s_try_method{"()Lnet/minecraft/util/math/BlockPos;", {"1.12.2"}},
			},
			{
				s_try_method{"func_174877_v", {"1.8.9","1.12.2"}},
			},
			{
				{"1.8.9","v"},
				{"1.12.2","v"},
			},
		}},
	}},
	{"Minecraft", {
		{"getNetHandler", {
			{
				s_try_method{"()Lnet/minecraft/client/network/NetHandlerPlayClient;", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_147114_u", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","v"},
				{"1.8.9","u"},
			},
		}},
		{"getMinecraft", {
			{
				s_try_method{"()Lnet/minecraft/client/Minecraft;", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_71410_x", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","B"},
				{"1.8.9","A"},
				{"1.12.2","z"},
			},
		}},
	}},
	{"AxisAlignedBB", {
		{"expand", {
			{
				s_try_method{"(DDD)Lnet/minecraft/util/AxisAlignedBB;", {"1.7.10","1.8.9"}},
				s_try_method{"(DDD)Lnet/minecraft/util/math/AxisAlignedBB;", {"1.12.2"}},
			},
			{
				s_try_method{"func_72314_b", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","b"},
				{"1.8.9","b"},
				{"1.12.2","b"},
			},
		}},
		{"isVecInside", {
			{
				s_try_method{"(Lnet/minecraft/util/Vec3;)Z", {"1.7.10","1.8.9"}},
				s_try_method{"(Lnet/minecraft/util/math/Vec3d;)Z", {"1.12.2"}},
			},
			{
				s_try_method{"func_72318_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
	{"World", {
		{"getEntityByID", {
			{
				s_try_method{"(I)Lnet/minecraft/entity/Entity;", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_73045_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
		{"isAirBlock", {
			{
				s_try_method{"(Lnet/minecraft/util/math/BlockPos;)Z", {"1.12.2"}},
				s_try_method{"(III)Z", {"1.7.10"}},
				s_try_method{"(Lnet/minecraft/util/BlockPos;)Z", {"1.8.9"}},
			},
			{
				s_try_method{"func_147437_c", {"1.7.10"}},
				s_try_method{"func_175623_d", {"1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","c"},
				{"1.8.9","d"},
				{"1.12.2","d"},
			},
		}},
	}},
	{"BlockPos", {
	}},
	{"IInventory", {
		{"getSizeInventory", {
			{
				s_try_method{"()I", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70302_i_", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","o_"},
				{"1.12.2","u_"},
			},
		}},
	}},
	{"Gui", {
		{"drawScaledCustomSizeModalRect", {
			{
				s_try_method{"(IIFFIIIIFF)V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_152125_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
	{"PlayerControllerMP", {
		{"sendUseItem", {
			{
				s_try_method{"(Lnet/minecraft/entity/player/EntityPlayer;Lnet/minecraft/world/World;Lnet/minecraft/item/ItemStack;)Z", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_78769_a", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
			},
		}},
		{"windowClick", {
			{
				s_try_method{"(IIILnet/minecraft/inventory/ClickType;Lnet/minecraft/entity/player/EntityPlayer;)Lnet/minecraft/item/ItemStack;", {"1.12.2"}},
				s_try_method{"(IIIILnet/minecraft/entity/player/EntityPlayer;)Lnet/minecraft/item/ItemStack;", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_78753_a", {"1.7.10","1.8.9"}},
				s_try_method{"func_187098_a", {"1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
	{"GameSettings", {
		{"isKeyDown", {
			{
				s_try_method{"(Lnet/minecraft/client/settings/KeyBinding;)Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_100015_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
	{"EntityLivingBase", {
		{"getHeldItem", {
			{
				s_try_method{"()Lnet/minecraft/item/ItemStack;", {"1.7.10","1.8.9"}},
				s_try_method{"(Lnet/minecraft/util/EnumHand;)Lnet/minecraft/item/ItemStack;", {"1.12.2"}},
			},
			{
				s_try_method{"func_70694_bm", {"1.7.10","1.8.9"}},
				s_try_method{"func_184586_b", {"1.12.2"}},
			},
			{
				{"1.7.10","be"},
				{"1.8.9","bA"},
				{"1.12.2","b"},
			},
		}},
		{"isOnSameTeam", {
			{
				s_try_method{"(Lnet/minecraft/entity/EntityLivingBase;)Z", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_142014_c", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","c"},
				{"1.8.9","c"},
			},
		}},
		{"getTeam", {
			{
				s_try_method{"()Lnet/minecraft/scoreboard/Team;", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_96124_cp", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","bt"},
				{"1.8.9","bO"},
			},
		}},
		{"getCurrentArmor", {
			{
				s_try_method{"(I)Lnet/minecraft/item/ItemStack;", {"1.8.9"}},
			},
			{
				s_try_method{"func_82169_q", {"1.8.9"}},
			},
			{
				{"1.8.9","q"},
			},
		}},
		{"getSwingProgress", {
			{
				s_try_method{"(F)F", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70678_g", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","k"},
				{"1.8.9","l"},
				{"1.12.2","m"},
			},
		}},
		{"getHealth", {
			{
				s_try_method{"()F", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_110143_aJ", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","aS"},
				{"1.8.9","bn"},
				{"1.12.2","bR"},
			},
		}},
	}},
	{"WorldClient", {
		{"removeEntityFromWorld", {
			{
				s_try_method{"(I)Lnet/minecraft/entity/Entity;", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_73028_b", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","b"},
				{"1.8.9","e"},
				{"1.12.2","e"},
			},
		}},
	}},
	{"EntityPlayer", {
		{"attackTargetEntityWithCurrentItem", {
			{
				s_try_method{"(Lnet/minecraft/entity/Entity;)V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_71059_n", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","r"},
				{"1.8.9","f"},
				{"1.12.2","f"},
			},
		}},
		{"closeScreen", {
			{
				s_try_method{"()V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_71053_j", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","k"},
				{"1.8.9","n"},
				{"1.12.2","q"},
			},
		}},
		{"getItemInUseCount", {
			{
				s_try_method{"()I", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_71052_bv", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","bx"},
				{"1.8.9","bR"},
			},
		}},
	}},
	{"MouseHelper", {
		{"ungrabMouseCursor", {
			{
				s_try_method{"()V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_74373_b", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","b"},
				{"1.8.9","b"},
				{"1.12.2","b"},
			},
		}},
		{"grabMouseCursor", {
			{
				s_try_method{"()V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_74372_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
	{"Vec3i", {
		{"getZ", {
			{
				s_try_method{"()I", {"1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_177952_p", {"1.8.9","1.12.2"}},
			},
			{
				{"1.8.9","p"},
				{"1.12.2","r"},
			},
		}},
		{"getX", {
			{
				s_try_method{"()I", {"1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_177958_n", {"1.8.9","1.12.2"}},
			},
			{
				{"1.8.9","n"},
				{"1.12.2","p"},
			},
		}},
		{"getY", {
			{
				s_try_method{"()I", {"1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_177956_o", {"1.8.9","1.12.2"}},
			},
			{
				{"1.8.9","o"},
				{"1.12.2","q"},
			},
		}},
	}},
	{"KeyBinding", {
		{"unpressKey", {
			{
				s_try_method{"()V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_74505_d", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","j"},
				{"1.8.9","j"},
				{"1.12.2","k"},
			},
		}},
	}},
	{"RenderItem", {
		{"renderItemAndEffectIntoGUI", {
			{
				s_try_method{"(Lnet/minecraft/entity/EntityLivingBase;Lnet/minecraft/item/ItemStack;II)V", {"1.12.2"}},
				s_try_method{"(Lnet/minecraft/client/gui/FontRenderer;Lnet/minecraft/client/renderer/texture/TextureManager;Lnet/minecraft/item/ItemStack;II)V", {"1.7.10"}},
				s_try_method{"(Lnet/minecraft/item/ItemStack;II)V", {"1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_82406_b", {"1.7.10"}},
				s_try_method{"func_180450_b", {"1.8.9","1.12.2"}},
				s_try_method{"func_184391_a", {"1.12.2"}},
			},
			{
				{"1.7.10","b"},
				{"1.8.9","b"},
				{"1.12.2","a"},
				{"1.12.2","b"},
			},
		}},
	}},
	{"ThreadDownloadImageData", {
		{"setBufferedImage", {
			{
				s_try_method{"(Ljava/awt/image/BufferedImage;)V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_147641_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
	{"Vec3", {
		{"distanceTo", {
			{
				s_try_method{"(Lnet/minecraft/util/Vec3;)D", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_72438_d", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","d"},
				{"1.8.9","f"},
			},
		}},
		{"addVector", {
			{
				s_try_method{"(DDD)Lnet/minecraft/util/Vec3;", {"1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_72441_c", {"1.7.10","1.8.9"}},
			},
			{
				{"1.7.10","c"},
				{"1.8.9","b"},
			},
		}},
	}},
	{"Item", {
		{"getIdFromItem", {
			{
				s_try_method{"(Lnet/minecraft/item/Item;)I", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				s_try_method{"func_150891_b", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				{"1.7.10","b"},
				{"1.12.2","a"},
				{"1.8.9","b"},
			},
		}},
	}},
	{"Entity", {
		{"isSprinting", {
			{
				s_try_method{"()Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70051_ag", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","ao"},
				{"1.8.9","aw"},
				{"1.12.2","aL"},
			},
		}},
		{"setSprinting", {
			{
				s_try_method{"(Z)V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70031_b", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","c"},
				{"1.8.9","d"},
				{"1.12.2","e"},
			},
		}},
		{"isSneaking", {
			{
				s_try_method{"()Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70093_af", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","an"},
				{"1.8.9","av"},
				{"1.12.2","aK"},
			},
		}},
		{"getCollisionBorderSize", {
			{
				s_try_method{"()F", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70111_Y", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","af"},
				{"1.8.9","ao"},
				{"1.12.2","aA"},
			},
		}},
		{"isInvisible", {
			{
				s_try_method{"()Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_82150_aj", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","ap"},
				{"1.8.9","ax"},
				{"1.12.2","aN"},
			},
		}},
		{"getDistanceToEntity", {
			{
				s_try_method{"(Lnet/minecraft/entity/Entity;)F", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70032_d", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","e"},
				{"1.8.9","g"},
				{"1.12.2","g"},
			},
		}},
		{"isEntityAlive", {
			{
				s_try_method{"()Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70089_S", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","Z"},
				{"1.8.9","ai"},
				{"1.12.2","au"},
			},
		}},
		{"canBeCollidedWith", {
			{
				s_try_method{"()Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_70067_L", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","R"},
				{"1.8.9","ad"},
				{"1.12.2","ap"},
			},
		}},
	}},
	{"ItemStack", {
		{"getMetadata", {
			{
				s_try_method{"()I", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				s_try_method{"func_77960_j", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				{"1.7.10","k"},
				{"1.12.2","i"},
				{"1.8.9","i"},
			},
		}},
		{"getItemUseAction", {
			{
				s_try_method{"()Lnet/minecraft/item/EnumAction;", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				s_try_method{"func_77975_n", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				{"1.7.10","o"},
				{"1.12.2","m"},
				{"1.8.9","m"},
			},
		}},
		{"getMaxDamage", {
			{
				s_try_method{"()I", {"1.12.2","1.8.9"}},
			},
			{
				s_try_method{"func_77958_k", {"1.12.2","1.8.9"}},
			},
			{
				{"1.12.2","j"},
				{"1.8.9","j"},
			},
		}},
	}},
	{"Container", {
		{"getSlot", {
			{
				s_try_method{"(I)Lnet/minecraft/inventory/Slot;", {"1.12.2","1.7.10","1.8.9"}},
			},
			{
				s_try_method{"func_75139_a", {"1.12.2","1.7.10","1.8.9"}},
			},
			{
				{"1.12.2","a"},
				{"1.7.10","a"},
				{"1.8.9","a"},
			},
		}},
	}},
	{"TextureManager", {
		{"bindTexture", {
			{
				s_try_method{"(Lnet/minecraft/util/ResourceLocation;)V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_110577_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
		{"loadTexture", {
			{
				s_try_method{"(Lnet/minecraft/util/ResourceLocation;Lnet/minecraft/client/renderer/texture/ITextureObject;)Z", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_110579_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
		{"deleteTexture", {
			{
				s_try_method{"(Lnet/minecraft/util/ResourceLocation;)V", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				s_try_method{"func_147645_c", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","c"},
				{"1.8.9","c"},
				{"1.12.2","c"},
			},
		}},
	}},
	{"Slot", {
		{"getStack", {
			{
				s_try_method{"()Lnet/minecraft/item/ItemStack;", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				s_try_method{"func_75211_c", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				{"1.7.10","d"},
				{"1.12.2","d"},
				{"1.8.9","d"},
			},
		}},
		{"getHasStack", {
			{
				s_try_method{"()Z", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				s_try_method{"func_75216_d", {"1.7.10","1.12.2","1.8.9"}},
			},
			{
				{"1.7.10","e"},
				{"1.12.2","e"},
				{"1.8.9","e"},
			},
		}},
	}},
	{"S18PacketEntityTeleport", {
		{"getEntityId", {
			{
				s_try_method{"()I", {"1.8.9"}},
			},
			{
				s_try_method{"func_149451_c", {"1.8.9"}},
			},
			{
				{"1.8.9","a"},
			},
		}},
	}},
	{"EnchantmentHelper", {
		{"getEnchantmentLevel", {
			{
				s_try_method{"(ILnet/minecraft/item/ItemStack;)I", {"1.7.10","1.8.9"}},
				s_try_method{"(Lnet/minecraft/enchantment/Enchantment;Lnet/minecraft/item/ItemStack;)I", {"1.12.2"}},
			},
			{
				s_try_method{"func_77506_a", {"1.7.10","1.8.9","1.12.2"}},
			},
			{
				{"1.7.10","a"},
				{"1.8.9","a"},
				{"1.12.2","a"},
			},
		}},
	}},
};