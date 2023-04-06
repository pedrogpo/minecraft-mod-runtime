#pragma once
#ifdef _DEBUG
#include <consoleapi.h>
#include <stdio.h>
#include "../../lib/xorstr/xorstring.h"
#include <iostream>
#include <shared_mutex>

namespace utils::console {
	inline FILE* f_out = nullptr;

	inline void attach_console() {
		AllocConsole();
		freopen_s(&f_out, xor ("conout$"), xor ("w"), stdout);
	}

	inline void free_console() {
		fclose(f_out);
		FreeConsole();
	}
}

enum class msg_type_t : std::uint32_t
{
	LNONE = 0,
	LDEBUG = 9,		/* blue */
	LSUCCESS = 10,	/* green */
	LERROR = 12,	/* red */
	LPROMPT = 11,	/* pink */
	LWARN = 14		/* yellow */
};

inline std::ostream& operator<< (std::ostream& os, const msg_type_t type)
{
	switch (type)
	{
	case msg_type_t::LDEBUG:	return os << ".";
	case msg_type_t::LSUCCESS:	return os << "+";
	case msg_type_t::LERROR:	return os << "!";
	case msg_type_t::LPROMPT:	return os << ">";
	case msg_type_t::LWARN:		return os << "*";
	default: return os << "";
	}
}

class logger
{
private:
	std::shared_timed_mutex mutex{};

public:
	template< typename ... arg >
	void print(const msg_type_t type, const std::string& format, arg ... a)
	{
		static auto* h_console = GetStdHandle(STD_OUTPUT_HANDLE);
		std::unique_lock<decltype(mutex)> lock(mutex);

		const size_t size = static_cast<size_t>(1) + std::snprintf(nullptr, 0, format.c_str(), a ...);
		const std::unique_ptr<char[]> buf(new char[size]);
		std::snprintf(buf.get(), size, format.c_str(), a ...);
		const auto formated = std::string(buf.get(), buf.get() + size - 1);

		if (type != msg_type_t::LNONE)
		{
			SetConsoleTextAttribute(h_console, static_cast<WORD>(type));
			std::cout << "[";
			std::cout << type;
			std::cout << "] ";
		}

		if (type == msg_type_t::LDEBUG)
			SetConsoleTextAttribute(h_console, 8 /* gray */);
		else
			SetConsoleTextAttribute(h_console, 15 /* white */);

		if (type == msg_type_t::LPROMPT)
			std::cout << formated;
		else
			std::cout << formated << std::endl;
	}
};

inline auto g_logger = logger();
#endif

#ifdef _DEBUG
#define log_debug(...)	g_logger.print( msg_type_t::LDEBUG, __VA_ARGS__ )
#define log_ok(...)		g_logger.print( msg_type_t::LSUCCESS, __VA_ARGS__ )
#define log_err(...)	g_logger.print( msg_type_t::LERROR, __VA_ARGS__ )
#define log_prompt(...) g_logger.print( msg_type_t::LPROMPT, __VA_ARGS__ )
#define log_warn(...)	g_logger.print( msg_type_t::LWARN, __VA_ARGS__ )
#define log_raw(...)	g_logger.print( msg_type_t::LNONE, __VA_ARGS__ )
#else
#define log_debug(...) 
#define log_ok(...)
#define log_err(...)
#define log_prompt(...)
#define log_warn(...)
#define log_raw(...)
#endif


