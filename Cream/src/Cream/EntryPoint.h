#pragma once
#ifdef CM_PLATFORM_WINDOWS
#include "Application.h"
#include <stdio.h>
extern Cream::Application* Cream::CreateApplication();

int main(int argc, char** argv)
{
	printf("Cream Engine.\n");
	auto app = Cream::CreateApplication();
	app->Run();
	delete app;
}
#endif

