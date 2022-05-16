#include "etodpch.h"
#include "ETOD/Core/Window.h"

#ifdef ETOD_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace ETOD
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef ETOD_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		ETOD_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}