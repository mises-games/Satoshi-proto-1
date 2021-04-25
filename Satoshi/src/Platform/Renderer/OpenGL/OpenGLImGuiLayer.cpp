#include "stpch.h"
#include "OpenGLImGuiLayer.h"

#include <Platform/Renderer/OpenGL/ImGuiOpenGLRenderer.h>
#include <Platform/Windows/GLFW/ImGuiGLFWindow.h>

#include <Satoshi/Application.h>

Satoshi::OpenGLImGuiLayer::OpenGLImGuiLayer() :
	ImGuiLayer()
{
}

Satoshi::OpenGLImGuiLayer::~OpenGLImGuiLayer()
{
}

void Satoshi::OpenGLImGuiLayer::OnAttach()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	
	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.6f,0.3f,0.2f,1.0f);
	
	Application& app = Application::Get();
	GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 410");
}

void Satoshi::OpenGLImGuiLayer::OnDetach()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Satoshi::OpenGLImGuiLayer::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Satoshi::OpenGLImGuiLayer::End()
{
	ImGuiIO& io = ImGui::GetIO();
	Application& app = Application::Get();
	io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Satoshi::OpenGLImGuiLayer::OnImGuiRender()
{
	bool show = true;
	ImGui::ShowDemoWindow(&show);
}
