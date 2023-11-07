#include <MAAT.h>
#include <MAAT/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public MAAT::Application
{
public:
	Sandbox(const MAAT::ApplicationSpecification& specification)
		: MAAT::Application(specification)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

MAAT::Application* MAAT::CreateApplication(MAAT::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../MAAT-Editor";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
