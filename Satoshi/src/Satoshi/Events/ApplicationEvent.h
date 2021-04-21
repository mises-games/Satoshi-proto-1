#ifndef APPLICATION_EVENT_H
#define APPLICATION_EVENT_H

#include "Event.h"
#include <Satoshi/Utils/StringHandler.h>

namespace Satoshi
{
	class WindowResizeEvent : public Event 
	{
	public:
		inline WindowResizeEvent(unsigned, unsigned);

		inline unsigned GetWidth() const;
		inline unsigned GetHeight() const;

		std::string ToString() const override;

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		inline WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppTickEvent : public Event
	{
	public:
		inline AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	
	class AppUpdateEvent : public Event
	{
	public:
		inline AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	
	class AppRenderEvent : public Event
	{
	public:
		inline AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

}

// Window Resize Implementation

Satoshi::WindowResizeEvent::WindowResizeEvent(unsigned width, unsigned height) :
	m_Width(width), m_Height(height)
{

}

inline unsigned Satoshi::WindowResizeEvent::GetWidth() const
{
	return m_Width;
}

inline unsigned Satoshi::WindowResizeEvent::GetHeight() const
{
	return m_Height;
}

inline std::string Satoshi::WindowResizeEvent::ToString() const
{
	std::string buffer = Satoshi::StringHandler::Concatenate<std::string,char>
		("WindowResizeEvent: ",	Satoshi::StringHandler::ParseNumber<std::string, char, unsigned>(m_Width));
	buffer = Satoshi::StringHandler::Concatenate<std::string,char>
		(buffer,", ");
	buffer = Satoshi::StringHandler::Concatenate<std::string,char>
		(buffer,Satoshi::StringHandler::ParseNumber<std::string, char, unsigned>(m_Height));
	return buffer;
}

#endif