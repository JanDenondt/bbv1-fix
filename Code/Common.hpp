#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#pragma comment (lib,"urlmon.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")
#include<tchar.h>
#include<urlmon.h>
#include <winsdkver.h>
#include <sys/types.h>
#include <sdkddkver.h>
#include <windows.h>
#include <intrin.h>
#include <winternl.h>
#include <timeapi.h>
#include <time.h>
#include <vadefs.h>
#include <stdint.h>
#include <cstdint>
#include <d3d11.h>

#include <cassert>
#include <cinttypes>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <vector>

#define BIGBASE_WIDE_IMPL(str) L ## str
#define BIGBASE_WIDE(str) BIGBASE_WIDE_IMPL(str)

#define BIGBASE_STRINGIZE_IMPL(x) #x
#define BIGBASE_STRINGIZE(x) BIGBASE_STRINGIZE_IMPL(x)

#define BIGBASE_NAME "BigBase"

namespace Big
{
	using namespace std::chrono_literals;
	namespace fs = std::filesystem;

	inline HMODULE g_Module{};
	inline std::atomic_bool g_Running = true;

	inline std::uint32_t g_SelectedPlayer{};

	inline bool g_LogScriptEvents = false;
}

#include "Settings.hpp"
#include "Logger.hpp"
#include "Util.hpp"
#include "SignatureScanner.hpp"
#include "Game.hpp"
#include "ScriptGlobal.hpp"
