#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace ETOD {

	class ETODnut : public Application
	{
	public:
		ETODnut(ApplicationCommandLineArgs args)
			: Application("EToD Editor 2D -Powered by SlaterVanS Studio.   Version: v0.0.1.1 alpha", args) //EToD Editor -Powered by SlaterVanS Studio. 
		{
			PushLayer(new EditorLayer());
		}

		~ETODnut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new ETODnut(args);
	}

}
