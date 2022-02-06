#pragma once


#ifdef ETOD_PLATFORM_WINDOWS

extern ETOD::Application* ETOD::CreateApplication();

int main(int argc,char** argv)
{
	ETOD::Log::Init();
	ETOD_CORE_WARN("初始化日志系统!");
	int a = 5;
	ETOD_INFO("开发者你好! 当前变量={0}",a);

	auto app = ETOD::CreateApplication();
	app->Run();
	delete app;
}

#endif