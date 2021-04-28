#include "stpch.h"
#include "OpenGLVertexArray.h"



static GLenum Satoshi::ShaderDataTypeToOpenGLBaseType(Satoshi::ShaderDataType type)
{
	switch (type)
	{
	case Satoshi::ShaderDataType::Float:    return GL_FLOAT;
	case Satoshi::ShaderDataType::Float2:   return GL_FLOAT;
	case Satoshi::ShaderDataType::Float3:   return GL_FLOAT;
	case Satoshi::ShaderDataType::Float4:   return GL_FLOAT;
	case Satoshi::ShaderDataType::Mat3:     return GL_FLOAT;
	case Satoshi::ShaderDataType::Mat4:     return GL_FLOAT;
	case Satoshi::ShaderDataType::Int:      return GL_INT;
	case Satoshi::ShaderDataType::Int2:     return GL_INT;
	case Satoshi::ShaderDataType::Int3:     return GL_INT;
	case Satoshi::ShaderDataType::Int4:     return GL_INT;
	case Satoshi::ShaderDataType::Bool:     return GL_BOOL;
	}

	ST_CORE_ASSERT(false, "Unknown ShaderDataType!");
	return 0;
}

Satoshi::OpenGLVertexArray::OpenGLVertexArray()
{
	glCreateVertexArrays(1, &m_RendererID);
}

Satoshi::OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

void Satoshi::OpenGLVertexArray::Bind() const
{
	glBindVertexArray(m_RendererID);
}

void Satoshi::OpenGLVertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void Satoshi::OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
	ST_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

	glBindVertexArray(m_RendererID);
	vertexBuffer->Bind();

	uint32_t index = 0;
	const auto& layout = vertexBuffer->GetLayout();
	for (const auto& element : layout)
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer
		(
			index, 
			element.GetComponentCount(), 
			ShaderDataTypeToOpenGLBaseType(element.Type), 
			element.Normalized ? GL_TRUE : GL_FALSE, 
			layout.GetStride(), 
			(const void *) element.Offset
		);
		index++;
	}
	m_VertexBuffers.push(vertexBuffer);
}

void Satoshi::OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
{
	glBindVertexArray(m_RendererID);
	indexBuffer->Bind();

	m_IndexBuffer = indexBuffer;
}
