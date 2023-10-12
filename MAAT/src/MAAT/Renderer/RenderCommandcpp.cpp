#include "mtpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h";

namespace MAAT {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}