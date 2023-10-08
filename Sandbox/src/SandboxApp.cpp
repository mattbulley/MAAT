#include <MAAT.h>

class Sandbox : public MAAT::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

MAAT::Application* MAAT::CreateApplication()
{
	return new Sandbox();
}