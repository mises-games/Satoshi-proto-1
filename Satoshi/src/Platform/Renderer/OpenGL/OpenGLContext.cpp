#include "stpch.h"
#include "OpenGLContext.h"

#include <glad/gl.h>

Satoshi::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) :
	m_WindowHandle(windowHandle)
{
}

void Satoshi::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGL(glfwGetProcAddress);
	ST_CORE_ASSERT(status, "Failed to initialize Glad!");

	ST_CORE_INFO("OpenGL Info:");
	ST_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
	ST_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
	ST_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
}

void Satoshi::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
