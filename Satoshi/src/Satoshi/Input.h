#ifndef INPUT_H
#define INPUT_H

#include <Satoshi/Core.h>

namespace Satoshi 
{
	class Input 
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
		inline static float GetAxisRawHorizontal() { return s_Instance->GetAxisRawHorizontalImpl(); }
		inline static float GetAxisRawVertical() { return s_Instance->GetAxisRawVerticalImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual float GetAxisRawHorizontalImpl() = 0;
		virtual float GetAxisRawVerticalImpl() = 0;
	private:
		static Input* s_Instance;
	};
}

#endif
