#ifndef OPEN_GL_CONTEXT_H
#define OPEN_GL_CONTEXT_H

#include <glfw/glfw3.h>
#include "Satoshi/Renderer/GraphicsContext.h"

#include <glm/glm.hpp>

namespace Satoshi 
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
		glm::vec4 m_BackgroundColor;
	};
}
#endif
