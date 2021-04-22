#ifndef LAYER_H
#define LAYER_H

#include <stpch.h>

#include <Satoshi/Core.h>
#include <Satoshi/Events/Event.h>

namespace Satoshi 
{
	class SATOSHI_API Layer 
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const;
	protected:
		std::string m_DebugName;
	};
}

#endif
