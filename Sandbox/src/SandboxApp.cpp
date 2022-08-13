#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public ETOD::Application
{
public:
	Sandbox(const ETOD::ApplicationSpecification& specification)
		: ETOD::Application(specification)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

ETOD::Application* ETOD::CreateApplication(ETOD::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../EToD-Editor";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}