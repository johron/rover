#pragma once

#include <memory>

#include <array>
#include <map>
#include <stack>
#include <string>

#include <variant>

#include <cassert>

#include <optional>
#include <random>

#if __GNUC__
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuseless-cast"
#pragma GCC diagnostic push
#include <experimental/net>
#pragma GCC diagnostic pop // "-Wuseless-cast"
#pragma GCC diagnostic pop // "-Wold-style-cast"
#pragma GCC diagnostic pop // "-Wsign-conversion"
#pragma GCC diagnostic pop // "-Wconversion"
#endif

#if	_MSC_VER
#pragma warning(push)
#pragma warning(disable : 4619) // #pragma warning: there is no warning number '4675'
#pragma warning(disable : 4996) // warning C4996: 'std::result_of': warning STL4014: std::result_of and std::result_of_t are deprecated in C++17. They are superseded by std::invoke_result and std::invoke_result_t. You can define _SILENCE_CXX17_RESULT_OF_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
#pragma warning(disable : 4242) // warning C4242: '=': conversion from 'int' to 'ADDRESS_FAMILY', possible loss of data
#if _WIN32 || _WIN64
#include "sdkddkver.h"
#endif
#include <experimental/net>
#pragma warning(pop)
#endif
