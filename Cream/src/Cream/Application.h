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
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	// Defined by client.
	Application* CreateApplication();
};

