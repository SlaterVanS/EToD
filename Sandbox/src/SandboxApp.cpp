#include <ETOD.h>

#include "imgui/imgui.h"

class ExampleLayer : public ETOD::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//ETOD_INFO("实例层::更新"); // ExampleLayer::Update

		if (ETOD::Input::IsKeyPressed(ETOD_KEY_TAB))
			ETOD_TRACE("Tab 键被按下！(循环)");  // Tab key is pressed!(poll)
	}

	virtual void OnImGuiRender() override
	{
		//ImGui::Begin("Test");
		//ImGui::Text("ETOD Engine Powered by SlaterVanS Studio!");
		//ImGui::End();
	}

	void OnEvent(ETOD::Event& event) override
	{
		if (event.GetEventType() == ETOD::EventType::KeyPressed)
		{
			ETOD::KeyPressedEvent& e = (ETOD::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ETOD_KEY_TAB)
				ETOD_TRACE("Tab 键被按下！(事件)"); // Tab key is pressed!(event)
			ETOD_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public ETOD::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

ETOD::Application* ETOD::CreateApplication()
{
	return new Sandbox();
}