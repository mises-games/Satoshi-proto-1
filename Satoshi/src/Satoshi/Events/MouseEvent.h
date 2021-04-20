#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include "Event.h"

namespace Satoshi 
{
	class MouseMovedEvent : public Event 
	{
	public:
		MouseMovedEvent(float, float);

		inline float GetX() const;
		inline float GetY() const;

		std::string ToString() const override;
	
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_PositionX;
		float m_PositionY;
	};

	class MouseScrolledEvent : public Event 
	{
	public:
		MouseScrolledEvent(float, float);

		inline float GetXOffset() const;
		inline float GetYOffset() const;

		std::string ToString() const override;
	
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	class MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const;

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int);

		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int);

		std::string ToString() const override;
	
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}

// Mouse Moved Implementations

inline Satoshi::MouseMovedEvent::MouseMovedEvent(float x, float y) :
	m_PositionX(x), m_PositionY(y)
{

}

inline float Satoshi::MouseMovedEvent::GetX() const
{
	return m_PositionX;
}

inline float Satoshi::MouseMovedEvent::GetY() const
{
	return m_PositionY;
}

std::string Satoshi::MouseMovedEvent::ToString() const
{
	return Satoshi::StringHandler::Concatenate<std::string>
	(
		4,
		"MouseMovedEvent: ", 
		Satoshi::StringHandler::ParseNumber<std::string, float>(m_PositionX),
		",",
		Satoshi::StringHandler::ParseNumber<std::string, float>(m_PositionY)
	);
}

// Mouse Scrolled Implementations

inline Satoshi::MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset) :
	m_XOffset(xOffset), m_YOffset(yOffset)
{

}

inline float Satoshi::MouseScrolledEvent::GetXOffset() const
{
	return m_XOffset;
}

inline float Satoshi::MouseScrolledEvent::GetYOffset() const
{
	return m_YOffset;
}

inline std::string Satoshi::MouseScrolledEvent::ToString() const
{
	/*
	return Satoshi::StringHandler::Concatenate<std::string>
	(
		4,
		"MouseScrolledEvent: ",
		Satoshi::StringHandler::ParseNumber<std::string, float>(m_XOffset),
		",",
		Satoshi::StringHandler::ParseNumber<std::string, float>(m_YOffset)
	);
	*/
	std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		("MouseScrolledEvent: ", Satoshi::StringHandler::ParseNumber<std::string, float>(m_XOffset));
	buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		(buffer, ", ");
	buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		(buffer, Satoshi::StringHandler::ParseNumber<std::string, char, float>(m_YOffset));
	return buffer;
}

// MouseButtonEvent

inline Satoshi::MouseButtonEvent::MouseButtonEvent(int button) :
	m_Button(button)
{

}

inline int Satoshi::MouseButtonEvent::GetMouseButton() const
{
	return m_Button;
}

// MouseButtonPressedEvent

Satoshi::MouseButtonPressedEvent::MouseButtonPressedEvent(int button) :
	MouseButtonEvent(button)
{

}

inline std::string Satoshi::MouseButtonPressedEvent::ToString() const
{
	std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		("MouseButtonPressedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_Button));
	return buffer;
}

// MouseButtonReleasedEvent

Satoshi::MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button) :
	MouseButtonEvent(button)
{

}

inline std::string Satoshi::MouseButtonReleasedEvent::ToString() const
{
	std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		("MouseButtonReleasedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_Button));
	return buffer;
}

#endif
