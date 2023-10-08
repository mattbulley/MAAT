#pragma once

#include "Core.h"

namespace MAAT {

	class MAAT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in CLIENT
	Application* CreateApplication();
}


