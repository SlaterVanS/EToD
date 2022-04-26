#include "etodpch.h"
#include "ETOD/Renderer/GraphicsContext.h"

#include "ETOD/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace ETOD {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    ETOD_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		ETOD_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}