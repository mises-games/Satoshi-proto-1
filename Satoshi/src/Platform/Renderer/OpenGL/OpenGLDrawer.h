#ifndef OPEN_GL_DRAWER_H
#define OPEN_GL_DRAWER_H

#include <Satoshi/Renderer/Drawer.h>

namespace Satoshi
{
	class OpenGLDrawer : public Drawer
	{
	public:
		virtual void Draw(uint32_t mode, int32_t count, uint32_t type, const void* indices) override;
	};

}

#endif
