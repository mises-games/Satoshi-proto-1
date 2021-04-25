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
		
		virtual void Begin() = 0;
		virtual void End() = 0;

	protected:
		float m_Time = 0.0f;
	};
}

#endif
