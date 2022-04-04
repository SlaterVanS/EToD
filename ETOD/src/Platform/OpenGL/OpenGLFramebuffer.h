#pragma once

#include "ETOD/Renderer/Framebuffer.h"

namespace ETOD {

	class OpenGLFramebuffer : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferSpecification& spec);
		virtual ~OpenGLFramebuffer();
		
		void Invalidate();

		virtual void Bind() override;
		virtual void Unbind() override;

<<<<<<< HEAD
		virtual void Resize(uint32_t width, uint32_t height) override;

=======
>>>>>>> a9f7a0b43492a2329f746bf7e65ad6686849ce82
		virtual  uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment; }

		virtual const FramebufferSpecification& GetSpecification() const override { return m_Specification; }
	private:
<<<<<<< HEAD
		uint32_t m_RendererID = 0;
		uint32_t m_ColorAttachment = 0, m_DepthAttachment = 0;
=======
		uint32_t m_RendererID;
		uint32_t m_ColorAttachment, m_DepthAttachment;
>>>>>>> a9f7a0b43492a2329f746bf7e65ad6686849ce82
		FramebufferSpecification m_Specification;
	};

}