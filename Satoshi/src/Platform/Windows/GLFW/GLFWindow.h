#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include <Satoshi/Window.h>

#include <GLFW/glfw3.h>

#include <Platform/Renderer/OpenGL/OpenGLImGuiLayer.h>
#include <Satoshi/Renderer/GraphicsContext.h>

#include <glm/glm.hpp>
#include <glad/gl.h>

namespace Satoshi 
{
	class GLFWindow : public Window 
	{
	public:
		GLFWindow(const WindowProps& props);
		virtual ~GLFWindow();

		void OnUpdate() override;

		unsigned GetWidth() const override;
		unsigned GetHeight() const override;

		void SetEventCallback(const EventCallbackFunction& callback) override;
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		virtual void SetBackgroundColor(float r, float g, float b, float a = 1.0f) override;
		virtual void SetClearParams(uint32_t Param) override;
		virtual void ApplyBackgroundColor() override;
		virtual void ApplyClearParams() override;

		virtual void* GetNativeWindow() const override;
		virtual void* GetImGuiLayer() const override;

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLenum m_ClearParams = 0;
		glm::vec4 m_BackgroundColor;
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		ImGuiLayer* m_ImGuiLayer;

		struct WindowData
		{
			std::string Title;
			unsigned Width, Height;
			bool VSync;

			EventCallbackFunction EventCallback;
		};
		WindowData m_Data;

		void SetGLCallbacks();
	};
}

#endif