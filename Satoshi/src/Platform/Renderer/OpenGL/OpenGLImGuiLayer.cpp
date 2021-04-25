#include "stpch.h"
#include "OpenGLImGuiLayer.h"

#include <Platform/Renderer/OpenGL/ImGuiOpenGLRenderer.h>
#include <Platform/Windows/GLFW/ImGuiGLFWindow.h>

#include <Satoshi/Application.h>
#include <Samples/Samples.h>

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
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.125f,0.75f,0.6f,1.0f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
	
	Application& app = Application::Get();
	GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

	io.Fonts->AddFontFromFileTTF("fonts/Roboto-Regular.ttf", 14);
	io.Fonts->AddFontFromFileTTF("fonts/OrelegaOne-Regular.ttf", 14);

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
	Satoshi::ImGuiCustomSample(NULL);
}
