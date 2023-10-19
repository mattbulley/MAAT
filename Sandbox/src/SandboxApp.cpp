#include <MAAT.h>
#include <MAAT/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public MAAT::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

MAAT::Application* MAAT::CreateApplication()
{
	return new Sandbox();
}
