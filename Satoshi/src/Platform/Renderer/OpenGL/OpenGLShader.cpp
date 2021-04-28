#include "stpch.h"
#include "OpenGLShader.h"

Satoshi::OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
{
	std::vector<ShaderInitializer> shaders;
	shaders.push_back({GL_VERTEX_SHADER, vertexSource});
	shaders.push_back({GL_FRAGMENT_SHADER, fragmentSource});
	m_RendererID = CreateShader(shaders);
}

Satoshi::OpenGLShader::~OpenGLShader()
{
	glDeleteProgram(m_RendererID);
}

void Satoshi::OpenGLShader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Satoshi::OpenGLShader::Unbind() const
{
	glUseProgram(0);
}

GLuint Satoshi::OpenGLShader::CompileShader(const std::string& source, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	const GLchar* src = source.c_str();

	glShaderSource(shader, 1, &src, 0);
	glCompileShader(shader);

	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled != GL_TRUE) 
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
	
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(shader,maxLength, &maxLength, &infoLog[0]);

		ST_CORE_ERROR("{0}", infoLog.data());
		ST_CORE_ASSERT(false, "Vertex shader compilation failure!");
		return 0;
	}

	return shader;
}

GLuint Satoshi::OpenGLShader::CreateShader(std::vector<ShaderInitializer> shaderSource)
{
	GLuint program = glCreateProgram();
	std::vector<unsigned> shaders;

	for (auto& shader : shaderSource)
		shaders.push_back(CompileShader(shader.Shader, shader.Type));
	
	for (auto& shader : shaders)
		glAttachShader(program, shader);
	glLinkProgram(program);

	int isLinked;
	glGetProgramiv(program,GL_LINK_STATUS, &isLinked);



	if (isLinked != GL_TRUE)
	{
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

		ST_CORE_ERROR("{0}", infoLog.data());
		ST_CORE_ASSERT(false, "Vertex shader compilation failure!");
		program = 0;
		for (auto& shader : shaders)
			glDeleteShader(shader);
	}

	for (auto& shader : shaders)
		glDetachShader(program, shader);

	return program;
}

std::string Satoshi::OpenGLShader::StringShaderType(unsigned shaderType)
{
	std::unordered_map<unsigned, std::string> shaderMapped;
	shaderMapped[GL_VERTEX_SHADER] = "vertex";
	shaderMapped[GL_FRAGMENT_SHADER] = "fragment";
	shaderMapped[GL_GEOMETRY_SHADER] = "geometry";

	if (shaderMapped.find(shaderType) == shaderMapped.end())
		return "";
	return shaderMapped[shaderType];
}
