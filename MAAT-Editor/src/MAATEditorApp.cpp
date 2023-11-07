#include <MAAT.h>
#include <MAAT/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace MAAT {

	class MAATEditor : public Application
	{
	public:
		MAATEditor(ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "MAAT Editor";
		spec.CommandLineArgs = args;

		return new MAATEditor(spec);
	}
}