#ifndef DRAWER_H
#define DRAWER_H

#include <cstdint>

namespace Satoshi 
{
	class Drawer 
	{
	public:
		virtual void Draw(uint32_t mode, int32_t count, uint32_t type, const void* indices) = 0;

		static Drawer* Create();
	};
}

#endif
