#include <MAAT.h>
#include <MAAT/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace MAAT {

	class MAATEditor : public Application
	{
	public:
		MAATEditor()
			: Application("MAAT Editor")
		{
			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~MAATEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new MAATEditor();
	}

}