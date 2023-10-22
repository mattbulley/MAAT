#pragma once

#include "MAAT/Core/Core.h"

namespace MAAT {

	struct FramebufferSpecification
	{
		uint32_t Width, Height;
		// FramebufferFormat Format =
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t GetColorAttachmentID() const = 0;

		virtual const FramebufferSpecification& GetSpecification() const = 0;

		static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
	};
}