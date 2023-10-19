#include "mtpch.h"
#include "MAAT/Renderer/RenderCommand.h"

namespace MAAT {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}