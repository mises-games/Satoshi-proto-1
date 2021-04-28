#include "stpch.h"
#include "VertexArray.h"

#include "Renderer.h"

#include <Platform/Renderer/OpenGL/OpenGLVertexArray.h>

Satoshi::VertexArray* Satoshi::VertexArray::Create()
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::None: ST_CORE_ASSERT(false, "You must set one Graphic API"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		//case RendererAPI::DirectX return new DirectXVertexArray();
		default: ST_CORE_ASSERT(false, "Unknown RendererAPI!"); return nullptr;
	}
}
