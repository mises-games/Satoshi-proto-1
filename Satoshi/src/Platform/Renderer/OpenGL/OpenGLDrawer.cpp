#include "stpch.h"
#include "OpenGLDrawer.h"

#include <glad/gl.h>

void Satoshi::OpenGLDrawer::Draw(uint32_t mode, int32_t count, uint32_t type, const void* indices)
{
	glDrawElements(mode, count, type, indices);
}
