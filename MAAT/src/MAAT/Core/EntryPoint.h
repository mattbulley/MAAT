#pragma once

#ifdef MAAT_PLATFORM_WINDOWS

extern MAAT::Application* MAAT::CreateApplication();

int main(int argc, char** argv)
{
	MAAT::Log::Init();
	MAAT_CORE_WARN("Initialized Log!");
	int a = 5;
	MAAT_INFO("Hello! Var={0}", a);
	
	auto app = MAAT::CreateApplication();
	app->Run();
	delete app;
}

#endif