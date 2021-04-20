#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include "Event.h"
#include <Satoshi/Utils/StringHandler.h>

namespace Satoshi
{
	class KeyEvent : public Event 
	{
	public:
		inline int GetKeyCode() const;

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int);

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int, int);

		inline int GetRepeatCount() const;
	
		std::string ToString() const override;
	
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyTyped)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(KeyReleased)
	};

}

// Key Event Implementation

inline int Satoshi::KeyEvent::GetKeyCode() const
{
	return m_KeyCode;
}

Satoshi::KeyEvent::KeyEvent(int keycode) :
	m_KeyCode(keycode)
{

}

// Key Pressed Event Implementation

Satoshi::KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) :
	KeyEvent(keycode), m_RepeatCount(repeatCount)
{
}

inline int Satoshi::KeyPressedEvent::GetRepeatCount() const
{
	return m_RepeatCount;
}

inline std::string Satoshi::KeyPressedEvent::ToString() const
{
	/*
	return Satoshi::StringHandler::Concatenate<std::string>
	(
		5,
		"KeyPressedEvent: ", 
		Satoshi::StringHandler::ParseNumber<std::string, int>(m_KeyCode), 
		" (", 
		Satoshi::StringHandler::ParseNumber<std::string, int>(m_RepeatCount),
		" repeats)"
	);
	*/

	std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		("KeyPressedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_KeyCode));
	buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		(buffer, " (");
	buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		(buffer, Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_RepeatCount));
	buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		(buffer, " repeats)");
	return buffer;
}

// Key Typed Event Implementation

Satoshi::KeyTypedEvent::KeyTypedEvent(int keycode) :
	KeyEvent(keycode)
{

}

inline std::string Satoshi::KeyTypedEvent::ToString() const
{
	std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		("KeyTypedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_KeyCode));
	return buffer;
}

// Key Released Event Implementation

Satoshi::KeyReleasedEvent::KeyReleasedEvent(int keycode) :
	KeyEvent(keycode)
{

}

inline std::string Satoshi::KeyReleasedEvent::ToString() const
{
	std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
		("KeyReleasedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_KeyCode));
	return buffer;
}

#endif
