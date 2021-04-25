#ifndef EVENT_H
#define EVENT_H

#include <stpch.h>
#include <Satoshi/Core.h>

#include <Satoshi/Utils/StringHandler.h>

namespace Satoshi
{
	enum class EventType 
	{
		None = 0,

		WindowClose, 
		WindowResize, 
		WindowFocus, 
		WindowLostFocus, 
		WindowMoved,
		
		AppTick, 
		AppUpdate, 
		AppRender,
		
		KeyPressed, 
		KeyReleased, 
		KeyTyped,
		
		MouseButtonPressed, 
		MouseButtonReleased, 
		MouseMoved, 
		MouseScrolled
	};

	enum EventCategory 
	{
		None = 0,
		EventCategoryApplication =  BIT(0),
		EventCategoryInput =		BIT(1),
		EventCategoryKeyboard =		BIT(2),
		EventCategoryMouse =		BIT(3),
		EventCategoryMouseButton =	BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
							   virtual EventType GetEventType() const override { return GetStaticType(); }\
							   virtual const char * GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual unsigned GetCategoryFlags() const override { return category; }

	class Event 
	{
		friend class EventDispatcher;
	public:
		bool m_Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual unsigned GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category);
		
	};

	class EventDispatcher 
	{
		template<typename T>
		using EventFunction = std::function<bool(T&)>;
	public:
		inline EventDispatcher(Event& event);
		template<typename T>
		bool Dispatch(EventFunction<T> function);
	private:
		Event& m_Event;
	};
}

inline bool Satoshi::Event::IsInCategory(EventCategory category)
{
	return GetCategoryFlags() & category;
}

inline Satoshi::EventDispatcher::EventDispatcher(Event& event) : m_Event(event)
{
}

template<typename T>
inline bool Satoshi::EventDispatcher::Dispatch(EventFunction<T> function)
{
	bool dispatched = (m_Event.GetEventType() == T::GetStaticType());
	if (dispatched)
		m_Event.m_Handled = function(*(T*)&m_Event);
	return dispatched;
}
#endif
