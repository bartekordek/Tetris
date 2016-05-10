#include "ObjectNode.h"

namespace MOGE
{

	ObjectNode::ObjectNode(): mFilePath("")
	{
	}

	ObjectNode::ObjectNode(const Path& filePath):mFilePath( filePath )
	{

	}

	ObjectNode::~ObjectNode()
	{
		FreeContent();
	}

	const std::shared_ptr<SurfaceWrapper> ObjectNode::GetContent()const
	{
		return surface;
	}

	const Path& ObjectNode::GetPath()const
	{
		return mFilePath;
	}

	void ObjectNode::SetSurface( const std::shared_ptr<SurfaceWrapper>& surface )
	{
		this->surface = surface;
	}

	void ObjectNode::FreeContent()
	{
		if( surface.get() )
		{
			SDL_FreeSurface( surface.get()->GetSdlSurface() );
		}
		surface = nullptr;
	}
}