#pragma once
#include "MAAT/Core/Core.h"

#ifdef MAAT_PLATFORM_WINDOWS

extern MAAT::Application* MAAT::CreateApplication();

int main(int argc, char** argv)
{
	MAAT::Log::Init();
	
	MAAT_PROFILE_BEGIN_SESSION("Startup", "MAATProfile-Startup.json");
	auto app = MAAT::CreateApplication();
	MAAT_PROFILE_END_SESSION();

	MAAT_PROFILE_BEGIN_SESSION("Runtime", "MAATProfile-Runtime.json");
	app->Run();
	MAAT_PROFILE_END_SESSION();

	MAAT_PROFILE_BEGIN_SESSION("Shutdown", "MAATProfile-Shutdown.json");
	delete app;
	MAAT_PROFILE_END_SESSION();
}

#endif