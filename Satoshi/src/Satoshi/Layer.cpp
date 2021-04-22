#include "stpch.h"
#include "Layer.h"

Satoshi::Layer::Layer(const std::string& debugName) :
	m_DebugName(debugName)
{
}

Satoshi::Layer::~Layer()
{
}

const std::string& Satoshi::Layer::GetName() const
{
	return m_DebugName;
}
