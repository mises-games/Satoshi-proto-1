#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace Satoshi 
{
	class Shader 
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0; 
		virtual void Unbind() const = 0;

		static Shader* Create(const std::string& vertexSource, const std::string& fragmentSource);
	};
}

#endif 
