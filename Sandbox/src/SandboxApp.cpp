#include <MAAT.h>

class ExampleLayer : public MAAT::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (MAAT::Input::IsKeyPressed(MAAT_KEY_TAB))
			MAAT_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(MAAT::Event& event) override
	{
		if (event.GetEventType() == MAAT::EventType::KeyPressed)
		{
			MAAT::KeyPressedEvent& e = (MAAT::KeyPressedEvent&)event;
			if (MAAT::Input::IsKeyPressed(MAAT_KEY_TAB))
				MAAT_TRACE("Tab key is pressed (event)!");
			MAAT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public MAAT::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

MAAT::Application* MAAT::CreateApplication()
{
	return new Sandbox();
}