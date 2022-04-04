#pragma once

#include "ETOD/Core/Core.h"

namespace ETOD {

	struct FramebufferSpecification
	{
		uint32_t Width, Height;
		// FramebufferFormat Format=
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		virtual void Bind() = 0;
		virtual void Unbind() = 0;

<<<<<<< HEAD
		virtual void Resize(uint32_t width, uint32_t height) = 0;

=======
>>>>>>> a9f7a0b43492a2329f746bf7e65ad6686849ce82
		virtual  uint32_t GetColorAttachmentRendererID() const = 0;

		virtual const FramebufferSpecification& GetSpecification() const = 0;

		static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
	};
}