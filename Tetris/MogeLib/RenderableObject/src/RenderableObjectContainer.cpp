#include "RenderableObjectContainer.h"
#include "RenderableObjectContainerImpl.h"

namespace MOGE
{
	RenderableObjectContainer::RenderableObjectContainer()
	{
		this->impl = new RenderableObjectContainerImpl();
	}

	RenderableObjectContainer::~RenderableObjectContainer()
	{
		delete this->impl;
		this->impl = nullptr;
	}
}