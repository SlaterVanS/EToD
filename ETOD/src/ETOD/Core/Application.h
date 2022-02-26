#pragma once

#include "Core.h"

#include "Window.h"
#include "ETOD/Core/LayerStack.h"
#include "ETOD/Events/Event.h"
#include "ETOD/Events/ApplicationEvent.h"

#include "ETOD/Core/Timestep.h"

#include "ETOD/ImGui/ImGuiLayer.h"

namespace ETOD {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};


	//To be define in CLIENT
	Application* CreateApplication();

}

