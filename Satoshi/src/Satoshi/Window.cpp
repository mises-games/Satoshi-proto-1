#include "stpch.h"
#include "Window.h"

#include "Platform/Windows/GLFW/GLFWindow.h"
#include "./Renderer/Renderer.h"

Satoshi::Window* Satoshi::Window::Create(const WindowProps& props)
{
	switch (Renderer::GetAPI())
	{
	case RendererAPI::None: ST_CORE_ASSERT(false, "You must set one Graphic API"); return nullptr;
	case RendererAPI::OpenGL: return new GLFWindow(props);
		//case RendererAPI::DirectX: return new DirectXVertexBuffer(vertices,size);
	default: ST_CORE_ASSERT(false, "Unknown RendererAPI!"); return nullptr;
	}
}
