#pragma once
#include "../../../includes.hpp"

namespace utils::game {
	[[nodiscard]] inline const auto get_game_handle() {
		return LI_FN(FindWindowA).safe_cached()(xor ("LWJGL"), nullptr);
	}
}