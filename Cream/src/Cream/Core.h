#include "cmpch.h"
#pragma once

#ifdef CM_PLATFORM_WINDOWS
	#ifdef CM_DYNAMIC_LINK
		#ifdef CM_BUILD_DLL
			#define CREAM_API __declspec(dllexport)
		#else
			#define CREAM_API __declspec(dllimport)
		#endif
	#else
		#define CREAM_API
	#endif
#else
	#error Cream only supports Windows!
#endif
#ifdef CM_ENABLE_ASSERTS
	#define CM_ASSERT(x, ...) { if(!(x)) { CM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CM_CORE_ASSERT(x, ...) { if(!(x)) { CM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CM_ASSERT(x, ...)
	#define CM_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)

#define CM_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
