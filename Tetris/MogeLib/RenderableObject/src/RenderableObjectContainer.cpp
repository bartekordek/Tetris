#include "RenderableObjectContainer.h"
#include "RenderableObjectContainerImpl.h"

namespace Moge
{
	RenderableObjectContainer::RenderableObjectContainer()
	{
		this->impl = new RenderableObjectContainerImpl();
	}

	RenderableObjectContainer::RenderableObjectContainer( const RenderableObjectContainer& renderableObjectContainer )
	{
		this->impl = new RenderableObjectContainerImpl( *renderableObjectContainer.impl );
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