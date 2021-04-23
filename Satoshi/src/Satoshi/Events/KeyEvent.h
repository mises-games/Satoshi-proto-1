#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include "Event.h"
#include <Satoshi/Utils/StringHandler.h>

namespace Satoshi
{
	class KeyEvent : public Event 
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode) :	m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount) :	KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }
	
		std::string ToString() const override 
		{
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
	
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override 
		{
			std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				("KeyTypedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_KeyCode));
			return buffer;
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) :	KeyEvent(keycode) {}

		std::string ToString() const override 
		{
			std::string buffer = Satoshi::StringHandler::Concatenate<std::string, char>
				("KeyReleasedEvent: ", Satoshi::StringHandler::ParseNumber<std::string, char, int>(m_KeyCode));
			return buffer;
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}

#endif
