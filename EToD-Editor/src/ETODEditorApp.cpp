#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace ETOD {

	class ETODnut : public Application
	{
	public:
<<<<<<< HEAD
		ETODnut(ApplicationCommandLineArgs args)
			: Application("EToD Editor -Powered by SlaterVanS Studio.", args) //EToD Editor -Powered by SlaterVanS Studio. 
=======
		ETODEditor(ApplicationCommandLineArgs args)
			: Application("EToD Editor -Powered by SlaterVanS Studio. ", args)
>>>>>>> c8d7e32c9608f05a2d6091a29a2123ccf7efd141
		{
			PushLayer(new EditorLayer());
		}

		~ETODnut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
<<<<<<< HEAD
		return new ETODnut(args);
=======
		return new ETODEditor(args);
>>>>>>> c8d7e32c9608f05a2d6091a29a2123ccf7efd141
	}

}
