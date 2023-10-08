#pragma once

#ifdef MAAT_PLATFORM_WINDOWS

extern MAAT::Application* MAAT::CreateApplication();

int main(int argc, char** argv)
{
	auto app = MAAT::CreateApplication();
	app->Run();
	delete app;
}

#endif