#ifndef APPLICATION_H
#define APPLICATION_H

#include <Satoshi/Core.h>
#include <Satoshi/Events/Event.h>
#include <Satoshi/Events/ApplicationEvent.h>

#include <Satoshi/Log.h>

#include <Satoshi/Window.h>
#include <Satoshi/LayerStack.h>
#include <Satoshi/ImGui/ImGuiLayer.h>
#include <Satoshi/Renderer/Buffer.h>
#include <Satoshi/Renderer/Shader.h>
#include <Satoshi/Renderer/VertexArray.h>
#include <Satoshi/Renderer/Drawer.h>

namespace Satoshi 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow();

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Drawer> m_Drawer;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running;
		LayerStack m_LayerStack;

		
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;
		
		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVertexArray;

		static Application* s_Instance;
		
	};

	Application* CreateApplication();
}

#endif
