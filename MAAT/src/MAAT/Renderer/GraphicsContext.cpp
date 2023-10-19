#include "mtpch.h"
#include "MAAT/Renderer/GraphicsContext.h"

#include "MAAT/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace MAAT {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    MAAT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		MAAT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}