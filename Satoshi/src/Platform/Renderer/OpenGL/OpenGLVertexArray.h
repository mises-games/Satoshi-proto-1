#ifndef OPEN_GL_VERTEX_ARRAY_H
#define OPEN_GL_VERTEX_ARRAY_H

#include "Satoshi/Renderer/VertexArray.h"
#include <glad/gl.h>

namespace Satoshi 
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type);

	class OpenGLVertexArray : public VertexArray 
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

		virtual const std::queue<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
	
	private:
		uint32_t m_RendererID;
		std::queue<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}

#endif
