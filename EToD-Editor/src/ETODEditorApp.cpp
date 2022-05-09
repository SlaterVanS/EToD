#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace ETOD {
	class ETODEditor : public Application
	{
	public:
		ETODEditor(ApplicationCommandLineArgs args)
			: Application("EToD Editor -Powered by SlaterVanS Studio. ", args)
		{
			PushLayer(new EditorLayer());
		}

		~ETODEditor()
		{

		}

	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new ETODEditor(args);
	}
}