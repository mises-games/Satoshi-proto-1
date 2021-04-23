#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include "Event.h"

namespace Satoshi 
{
	class MouseMovedEvent : public Event 
	{
	public:
		MouseMovedEvent(float x, float y) :	m_PositionX(x), m_PositionY(y) {}

		inline float GetX() const { return m_PositionX; }
		inline float GetY() const { return m_PositionY; }

		std::string ToString() const override 
		{
			std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				("MouseMovedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, float>(m_PositionX));
			buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				(buffer, ",");
			buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				(buffer, Satoshi::StringHandler::ParseNumber<std::string, char, float>(m_PositionY));
			return buffer;
		}
	
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_PositionX;
		float m_PositionY;
	};

	class MouseScrolledEvent : public Event 
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) :	m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

		std::string ToString() const override 
		{
			std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				("MouseScrolledEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, float>(m_XOffset));
			buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				(buffer, ", ");
			buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				(buffer, Satoshi::StringHandler::ParseNumber<std::string, char, float>(m_YOffset));
			return buffer;
		}
	
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : m_Button(button) {}

		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override 
		{
			std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				("MouseButtonPressedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_Button));
			return buffer;
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override 
		{
			std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				("MouseButtonReleasedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_Button));
			return buffer;
		}
	
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

#endif
