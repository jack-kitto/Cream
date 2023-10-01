#pragma once
#ifdef CM_PLATFORM_WINDOWS
#include "Application.h"
extern Cream::Application* Cream::CreateApplication();

int main(int argc, char** argv)
{
	Cream::Log::Init();
	CM_CLIENT_INFO("Initialised Client Logger!");
	CM_CORE_WARN("Initialised Core Logger!");
	auto app = Cream::CreateApplication();
	app->Run();
	delete app;
}
#endif

