#include <Satoshi.h>

class Sandbox : public Satoshi::Application 
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Satoshi::Application* Satoshi::CreateApplication()
{
	return new Sandbox();
}