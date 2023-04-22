#pragma once

namespace utils::string {
	inline const auto replace_all(std::string str, const std::string& from, const std::string& to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}
		return str;
	}

	inline std::vector<std::string> explode(std::string const& s, char delim) {
		std::vector<std::string> result;
		std::istringstream iss(s);
		for (std::string token; std::getline(iss, token, delim); ) {
			result.push_back(std::move(token));
		}
		return result;
	}
}