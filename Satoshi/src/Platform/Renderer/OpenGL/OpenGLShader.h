#ifndef OPEN_GL_SHADER_H
#define OPEN_GL_SHADER_H

#include <Satoshi/Renderer/Shader.h>

#include <glad/gl.h>

namespace Satoshi
{
	struct ShaderInitializer 
	{
		unsigned Type;
		std::string Shader;
	};

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		uint32_t m_RendererID;

		GLuint CompileShader(const std::string& source, GLenum shaderType);
		GLuint CreateShader(std::vector<ShaderInitializer> shader);
		std::string StringShaderType(unsigned shaderType);
	};
}

#endif
