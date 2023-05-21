#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "EditorLayer.h"
#include "ETOD/Version/VersionControl.h"

namespace ETOD {

	class EToD_Editor : public Application
	{
	public:
		EToD_Editor(const ApplicationSpecification& spec)
			: Application(spec) //EToD Editor -Powered by SlaterVanS Studio. 
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		// Get Internet Version
		std::string main_version = "0";
		std::string test_version = " alpha";
		std::string dot_version = ".";
		std::string space_version = " ";
		std::string latest_version = get_latest_version();

		// Get Local Version
		std::string local_version = read_local_version();

		// Null

		ApplicationSpecification spec;
		spec.Name = "EToD Editor 2D - Powered by SlaterVanS Studio.   Version: v0.0." + main_version + dot_version + local_version + space_version + test_version;
		spec.CommandLineArgs = args;

		return new EToD_Editor(spec);
	}

}
