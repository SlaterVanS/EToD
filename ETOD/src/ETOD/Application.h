#pragma once

#include "Core.h"

#include "Window.h"
#include "ETOD/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"


namespace ETOD {

	class ETOD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	//To be define in CLIENT
	Application* CreateApplication();

}

