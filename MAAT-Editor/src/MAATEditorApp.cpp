#include <MAAT.h>
#include <MAAT/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace MAAT {

	class MAATEditor : public Application
	{
	public:
		MAATEditor(ApplicationCommandLineArgs args)
			: Application("MAAT Editor")
		{
			PushLayer(new EditorLayer());
		}

		~MAATEditor()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new MAATEditor(args);
	}

}