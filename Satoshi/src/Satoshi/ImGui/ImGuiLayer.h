#ifndef IM_GUI_LAYER_H
#define IM_GUI_LAYER_H

#include <Satoshi/Layer.h>

#include <Satoshi/Events/MouseEvent.h>
#include <Satoshi/Events/KeyEvent.h>
#include <Satoshi/Events/ApplicationEvent.h>

namespace Satoshi 
{
	class SATOSHI_API ImGuiLayer : public Layer 
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

		float m_Time = 0.0f;
	};
}

#endif
