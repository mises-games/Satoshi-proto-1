#include "stpch.h"
#include "WindowsInput.h"

#include "Satoshi/Application.h"
#include <GLFW/glfw3.h>
#include <Satoshi/KeyCodes.h>

Satoshi::Input* Satoshi::Input::s_Instance = new WindowsInput();

bool Satoshi::WindowsInput::IsKeyPressedImpl(int keycode)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetKey(window, keycode);
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Satoshi::WindowsInput::IsMouseButtonPressedImpl(int button)
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

std::pair<float, float> Satoshi::WindowsInput::GetMousePositionImpl()
{
    auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

	return { (float)xpos, (float)ypos };
}

float Satoshi::WindowsInput::GetMouseXImpl()
{
    auto [x,y] = GetMousePositionImpl();

    return x;
}

float Satoshi::WindowsInput::GetMouseYImpl()
{
    auto [x, y] = GetMousePositionImpl();

    return y;
}

float Satoshi::WindowsInput::GetAxisRawHorizontalImpl()
{
    float axis = .0f;
    if (IsKeyPressedImpl(ST_KEY_A) || IsKeyPressedImpl(ST_KEY_LEFT))
        axis -= 1.0f;
    if (IsKeyPressedImpl(ST_KEY_D) || IsKeyPressedImpl(ST_KEY_RIGHT))
        axis += 1.0f;
    return axis;
}

float Satoshi::WindowsInput::GetAxisRawVerticalImpl()
{
    float axis = .0f;
    if (IsKeyPressedImpl(ST_KEY_S) || IsKeyPressedImpl(ST_KEY_DOWN))
        axis -= 1.0f;
    if (IsKeyPressedImpl(ST_KEY_W) || IsKeyPressedImpl(ST_KEY_UP))
        axis += 1.0f;
    return axis; return 0.0f;
}
