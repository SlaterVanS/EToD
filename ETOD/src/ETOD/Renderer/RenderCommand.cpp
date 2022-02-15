#include "etodpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace ETOD {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}