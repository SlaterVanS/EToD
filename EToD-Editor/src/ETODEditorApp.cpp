#include <ETOD.h>
#include <ETOD/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace ETOD {
	class ETODEditor : public Application
	{
	public:
		ETODEditor()
			: Application("EToD Editor -Powered by SlaterVanS Studio.")
		{
			PushLayer(new EditorLayer());
		}

		~ETODEditor()
		{

		}

	};

	Application* CreateApplication()
	{
		return new ETODEditor();
	}
}