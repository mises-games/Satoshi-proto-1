#ifndef WINDOWS_INPUT_H
#define WINDOWS_INPUT_H

#include <Satoshi/Input.h>

namespace Satoshi 
{

	class GLFWindowInput : public Input 
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
		virtual float GetAxisRawHorizontalImpl() override;
		virtual float GetAxisRawVerticalImpl() override;
	};

}

#endif
