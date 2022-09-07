#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "EditorLayer.h"

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
		ApplicationSpecification spec;
		spec.Name = "EToD Editor 2D -Powered by SlaterVanS Studio.   Version: v0.0.1.1 alpha";
		spec.CommandLineArgs = args;

		return new EToD_Editor(spec);
	}

}
