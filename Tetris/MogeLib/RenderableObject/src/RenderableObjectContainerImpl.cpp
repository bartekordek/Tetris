#include "RenderableObjectContainerImpl.h"

namespace MogeLib
{
	RenderableObjectContainerImpl::RenderableObjectContainerImpl()
	{
	}

	RenderableObjectContainerImpl::~RenderableObjectContainerImpl()
	{
	}

	void RenderableObjectContainerImpl::addObject( const std::shared_ptr<ObjectNode>& node )
	{
		std::lock_guard<std::mutex> guard( nodeMutex );
		this->nodes.insert( node );
	}
}