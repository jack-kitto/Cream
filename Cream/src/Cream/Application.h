#pragma once

#include "Core.h"
namespace Cream {

	class CREAM_API Application
	{
	public:
		Application();
		virtual ~Application();
		static void Run();
	};

	// Defined by client.
	Application* CreateApplication();
};

