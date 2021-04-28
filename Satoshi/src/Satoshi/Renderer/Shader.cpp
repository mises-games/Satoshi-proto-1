#include "stpch.h"
#include "Shader.h"

#include "Renderer.h"

#include <Platform/Renderer/OpenGL/OpenGLShader.h>

Satoshi::Shader* Satoshi::Shader::Create(const std::string& vertexSource, const std::string& fragmentSource)
{
	switch (Renderer::GetAPI())
	{
		case RendererAPI::None: ST_CORE_ASSERT(false, "You must set one Graphic API"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLShader(vertexSource, fragmentSource);
		//case RendererAPI::DirectX: return new DirectXVertexBuffer(vertices,size);
		default: ST_CORE_ASSERT(false, "Unknown RendererAPI!"); return nullptr;
	}

}
