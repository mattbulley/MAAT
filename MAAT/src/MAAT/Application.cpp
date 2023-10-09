#include "Application.h"

#include "MAAT/Events/ApplicationEvent.h"
#include "MAAT/Log.h"

namespace MAAT {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MAAT_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MAAT_TRACE(e);
		}

		while (true);
	}
}

