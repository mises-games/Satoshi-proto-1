#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include <Satoshi/Window.h>

#include <GLFW/glfw3.h>
#include <glad/gl.h>

namespace Satoshi 
{
	class SATOSHI_API WindowsWindow : public Window 
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned GetWidth() const override;
		unsigned GetHeight() const override;

		void SetEventCallback(const EventCallbackFunction& callback) override;
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const;

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

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