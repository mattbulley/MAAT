#include "mtpch.h"
#include "MAAT/Renderer/Framebuffer.h"

#include "MAAT/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace MAAT {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    MAAT_CORE_ASSERT(false, "RendererAPI::None   is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		MAAT_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}