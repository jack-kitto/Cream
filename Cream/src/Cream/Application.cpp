#include "cmpch.h"
#include "Application.h"
#include "Cream/Events/ApplicationEvent.h"

namespace Cream {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	};
	Application::~Application()
	{

	}
	void Application::Run()
	{
		while (m_Running) {
			m_Window->OnUpdate();
		};
	};
}
