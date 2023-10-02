#include "cmpch.h"
#pragma once

#ifdef CM_PLATFORM_WINDOWS
	#ifdef CM_BUILD_DLL
		#define CREAM_API __declspec(dllexport)
	#else
		#define CREAM_API __declspec(dllimport)
	#endif
#else
	#error Cream only supports Windows!
#endif
#define BIT(x) (1 << x)
