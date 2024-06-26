#include "mtpch.h"
#include "MAAT/Renderer/VertexArray.h"

#include "MAAT/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace MAAT {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    MAAT_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		MAAT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}