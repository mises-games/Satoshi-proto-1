#include "stpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include <Platform/Renderer/OpenGL/OpenGLBuffer.h>

Satoshi::VertexBuffer* Satoshi::VertexBuffer::Create(void* vertices, uint32_t size)
{
    switch (Renderer::GetAPI()) 
    {
        case RendererAPI::None: ST_CORE_ASSERT(false, "You must set one Graphic API"); return nullptr;
        case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices,size);
        //case RendererAPI::DirectX: return new DirectXVertexBuffer(vertices,size);
        default: ST_CORE_ASSERT(false, "Unknown RendererAPI!"); return nullptr;
    }
}

Satoshi::IndexBuffer* Satoshi::IndexBuffer::Create(uint32_t* indices, uint32_t count)
{
    switch (Renderer::GetAPI())
    {
        case RendererAPI::None: ST_CORE_ASSERT(false, "You must set one Graphic API"); return nullptr;
        case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices,count);
        //case RendererAPI::DirectX: return new DirectXVertexBuffer(indices,size);
        default: ST_CORE_ASSERT(false, "Unknown RendererAPI!"); return nullptr;
    }
}
