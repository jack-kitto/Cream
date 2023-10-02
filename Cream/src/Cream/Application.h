#pragma once
#include "Core.h"
#include "Cream/Events/ApplicationEvent.h"

namespace Cream {

	class CREAM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// Defined by client.
	Application* CreateApplication();
};

