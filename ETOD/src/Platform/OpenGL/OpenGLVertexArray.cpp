#include "etodpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace ETOD {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case ETOD::ShaderDataType::Float:       return GL_FLOAT;
			case ETOD::ShaderDataType::Float2:      return GL_FLOAT;
			case ETOD::ShaderDataType::Float3:      return GL_FLOAT;
			case ETOD::ShaderDataType::Float4:      return GL_FLOAT;
			case ETOD::ShaderDataType::Mat3:        return GL_FLOAT;
			case ETOD::ShaderDataType::Mat4:        return GL_FLOAT;
			case ETOD::ShaderDataType::Int:         return GL_INT;
			case ETOD::ShaderDataType::Int2:        return GL_INT;
			case ETOD::ShaderDataType::Int3:        return GL_INT;
			case ETOD::ShaderDataType::Int4:        return GL_INT;
			case ETOD::ShaderDataType::Bool:        return GL_BOOL;
		}
		ETOD_CORE_ASSERT(false, " 未知着色器数据类型！"); //Unknow ShaderDataType!
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		ETOD_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		ETOD_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		ETOD_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		ETOD_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		ETOD_PROFILE_FUNCTION();

		ETOD_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), " 顶点缓冲区没有布局！");  //Vertex Buffer has no layout!

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		ETOD_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffers = indexBuffer;
	}
}