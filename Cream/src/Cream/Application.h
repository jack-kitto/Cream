#pragma once

#include "Core.h"

#include "Window.h"
#include "Cream/LayerStack.h"
#include "Cream/Events/Event.h"
#include "Cream/Events/ApplicationEvent.h"
#include "ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		ImGuiLayer* m_ImGuiLayer;

		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
