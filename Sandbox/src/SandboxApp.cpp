#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"
#include "ETOD/Version/VersionControl.h"

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
	// Get Internet Version
	std::string main_version = "0";
	std::string test_version = " alpha";
	std::string dot_version = ".";
	std::string space_version = " ";
	std::string latest_version = get_latest_version();

	// Get Local Version
	std::string local_version = read_local_version();

	ApplicationSpecification spec;
	spec.Name = "Sandbox  - Powered by EToD Engine.  Engine Version: v0.0." + main_version + dot_version + local_version + space_version + test_version;
	spec.WorkingDirectory = "../EToD-Editor";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
