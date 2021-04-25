#ifndef OPEN_GL_IM_GUI_LAYER_H
#define OPEN_GL_IM_GUI_LAYER_H

#include <Satoshi/ImGui/ImGuiLayer.h>

namespace Satoshi 
{
	class OpenGLImGuiLayer : public ImGuiLayer
	{
	public:
		OpenGLImGuiLayer();
		~OpenGLImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		virtual void Begin() override;
		virtual void End() override;
	};
}

#endif
