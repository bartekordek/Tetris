#include "RenderableObjectContainer.h"
#include "RenderableObjectContainerImpl.h"

namespace MogeLib
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

	void RenderableObjectContainer::addObject( const std::shared_ptr< ObjectNode >& node )
	{
		this->impl->addObject( node );
	}

}