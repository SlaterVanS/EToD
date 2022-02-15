#include "etodpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace ETOD {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:      ETOD_CORE_ASSERT(false, "RendererAPI::None is currently  not supported!"); return nullptr;
			case RendererAPI::OpenGL:    return new OpenGLVertexArray();
		}

		ETOD_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}