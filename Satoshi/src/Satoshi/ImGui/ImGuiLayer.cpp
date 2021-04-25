#include <stpch.h>
#include "ImGuiLayer.h"

#include <imgui.h>
#include <Platform/Renderer/OpenGL/ImGuiOpenGLRenderer.h>
#include <Platform/Windows/GLFW/ImGuiGLFWindow.h>

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <Satoshi/Application.h>

Satoshi::ImGuiLayer::ImGuiLayer() : 
	Layer("ImGuiLayer")
{
}

Satoshi::ImGuiLayer::~ImGuiLayer()
{
}