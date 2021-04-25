#ifndef WINDOW_H
#define WINDOW_H

#include <stpch.h>

#include <Satoshi/Core.h>
#include <Satoshi/Events/Event.h>

namespace Satoshi 
{
	struct WindowProps 
	{
		std::string Title;
		unsigned Width;
		unsigned Height;

		WindowProps
		(
			const std::string& title = "Satoshi Engine",
			unsigned width = 1280,
			unsigned height = 720
		) :
			Title(title), Width(width), Height(height)
		{
		}
	};

	class Window 
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned GetWidth() const = 0;
		virtual unsigned GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction&) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		virtual void* GetImGuiLayer() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}

#endif
