#include <ETOD.h>

class Sandbox : public ETOD::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

ETOD::Application* ETOD::CreateApplication()
{
	return new Sandbox();
}