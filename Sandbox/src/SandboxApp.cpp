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
		MAAT_INFO("ExampleLayer::Update");
	}

	void OnEvent(MAAT::Event& event) override
	{
		MAAT_TRACE("{0}", event);
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