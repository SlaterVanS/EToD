#include <ETOD.h>

class ExampleLayer : public ETOD::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ETOD_INFO("ÊµÀý²ã::¸üÐÂ"); //ExampleLayer::Update
	}

	void OnEvent(ETOD::Event& event) override
	{
		//ETOD_TRACE("{0}", event);
	}

};

class Sandbox : public ETOD::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new ETOD::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

ETOD::Application* ETOD::CreateApplication()
{
	return new Sandbox();
}