#pragma once
#include "Core.h"

namespace Cream {

	class CREAM_API Application
	{
	public:
		Application();
		virtual ~Application();
		 void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined by client.
	Application* CreateApplication();
};

