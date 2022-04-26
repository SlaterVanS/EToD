#include "etodpch.h"
#include "ETOD/Renderer/RenderCommand.h"

namespace ETOD {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}