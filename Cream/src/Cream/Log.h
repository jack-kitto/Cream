#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Cream {
	class CREAM_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};


#define CM_CORE_TRACE(...) ::Cream::Log::GetClientLogger()->trace(__VA_ARGS__);
#define CM_CORE_ERROR(...) ::Cream::Log::GetClientLogger()->error(__VA_ARGS__);
#define CM_CORE_INFO(...) ::Cream::Log::GetClientLogger()->info(__VA_ARGS__);
#define CM_CORE_WARN(...) ::Cream::Log::GetClientLogger()->warn(__VA_ARGS__);
#define CM_CORE_FATAL(...) ::Cream::Log::GetClientLogger()->fatal(__VA_ARGS__);

#define CM_CLIENT_TRACE(...) ::Cream::Log::GetClientLogger()->trace(__VA_ARGS__);
#define CM_CLIENT_ERROR(...) ::Cream::Log::GetClientLogger()->error(__VA_ARGS__);
#define CM_CLIENT_INFO(...) ::Cream::Log::GetClientLogger()->info(__VA_ARGS__);
#define CM_CLIENT_WARN(...) ::Cream::Log::GetClientLogger()->warn(__VA_ARGS__);
#define CM_CLIENT_FATAL(...) ::Cream::Log::GetClientLogger()->fatal(__VA_ARGS__);
