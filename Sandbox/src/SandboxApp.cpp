#include <Satoshi.h>

class Sandbox : public Satoshi::Application 
{
public:
	Sandbox() 
	{
		PushOverlay(new Satoshi::ImGuiLayer());
	}
	~Sandbox() {}
};

Satoshi::Application* Satoshi::CreateApplication()
{
	return new Sandbox();
}
