#include "ObjectNode.h"

namespace MOGE
{

	ObjectNode::ObjectNode()
	{
	}

	ObjectNode::ObjectNode( const Path& filePath )
	{

	}

	ObjectNode::~ObjectNode()
	{
		FreeContent();
	}

	const std::shared_ptr<SDL_Surface> ObjectNode::GetContent()const
	{
		return surface;
	}

	void ObjectNode::FreeContent()
	{
		SDL_FreeSurface( surface.get() );
		surface = nullptr;
	}
}