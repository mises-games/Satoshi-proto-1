#ifndef IM_GUI_LAYER_H
#define IM_GUI_LAYER_H

#include <Satoshi/Layer.h>
#include <Satoshi/Core.h>

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
		float m_Time = 0.0f;
	};
}

#endif
