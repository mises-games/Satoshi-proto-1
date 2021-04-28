#ifndef RENDERER_H
#define RENDERER_H

namespace Satoshi
{
	enum class RendererAPI 
	{
		None = 0,
		OpenGL = 1,
		DirectX = 2
	};

	class Renderer 
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
		inline static void SetAPI(RendererAPI api) { s_RendererAPI = api; }
	private:
		static RendererAPI s_RendererAPI;
	};
}

#endif 
