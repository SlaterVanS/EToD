#pragma once

#include "ETOD/Core/Base.h"

#include "ETOD/Core/Window.h"
#include "ETOD/Core/LayerStack.h"
#include "ETOD/Events/Event.h"
#include "ETOD/Events/ApplicationEvent.h"

#include "ETOD/Core/Timestep.h"

#include "ETOD/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace ETOD {

	class Application
	{
	public:
		Application(const std::string& name = "EToD App -Powered by SlaterVanS Studio.");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}