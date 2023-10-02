#include "cmpch.h"
#include "Application.h"
#include "Cream/Events/ApplicationEvent.h"

namespace Cream {
	Application::Application()
	{

	};
	Application::~Application()
	{

	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CM_CORE_TRACE(e.ToString());
		}
		while (true) {};
	};
}
