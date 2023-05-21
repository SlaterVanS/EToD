#pragma once

#include "ETOD/Core/Base.h"

#include "ETOD/Core/Window.h"
#include "ETOD/Core/LayerStack.h"
#include "ETOD/Events/Event.h"
#include "ETOD/Events/ApplicationEvent.h"

#include "ETOD/Core/Timestep.h"

#include "ETOD/Version/VersionControl.h"

#include "ETOD/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace ETOD {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			ETOD_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	struct ApplicationSpecification
	{		
		// Get Internet Version
		std::string main_version = "0";
		std::string test_version = " alpha";
		std::string dot_version = ".";
		std::string space_version = " ";
		std::string latest_version = get_latest_version();

		// Get Local Version
		std::string local_version = read_local_version();

		std::string Name = "EToD 2D App -Powered by SlaterVanS Studio.   Version: v0.0." + main_version + dot_version + local_version + space_version + test_version;
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }

		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

		void SubmitToMainThread(const std::function<void()>& function);
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		void ExecuteMainThreadQueue();
	private:
		ApplicationSpecification m_Specification;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

		std::vector<std::function<void()>> m_MainThreadQueue;
		std::mutex m_MainThreadQueueMutex;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}