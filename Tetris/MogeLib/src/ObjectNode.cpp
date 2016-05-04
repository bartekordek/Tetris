#include "ObjectNode.h"

namespace MOGE
{

	ObjectNode::ObjectNode()
	{
	}


	ObjectNode::~ObjectNode()
	{
	}

	void ObjectNode::FreeContent()
	{
		SDL_FreeSurface( surface.get() );
	}
}