#include "stpch.h"
#include "Drawer.h"

#include "Renderer.h"
#include <Platform/Renderer/OpenGL/OpenGLDrawer.h>

Satoshi::Drawer* Satoshi::Drawer::Create()
{
    switch (Renderer::GetAPI()) 
    {
    case RendererAPI::None: ST_CORE_ASSERT(false, "You must set one Graphic API"); return nullptr;
    case RendererAPI::OpenGL: return new OpenGLDrawer();
    //case RendererAPI::DirectX:
    default: ST_CORE_ASSERT(false, "Unknown RendererAPI!"); return nullptr;
    }
}
