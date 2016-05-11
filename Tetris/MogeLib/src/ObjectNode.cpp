#include "ObjectNode.h"

namespace MOGE
{

	ObjectNodeContent::ObjectNodeContent(): mFilePath("")
	{
	}

	ObjectNodeContent::ObjectNodeContent(const Path& filePath):mFilePath( filePath )
	{

	}

	ObjectNodeContent::~ObjectNodeContent()
	{
		FreeContent();
	}

	const ImageSurface& ObjectNodeContent::GetContent()const
	{
		return surface;
	}

	const Path& ObjectNodeContent::GetPath()const
	{
		return mFilePath;
	}

	void ObjectNodeContent::SetSurface( const ImageSurface& surface )
	{
		this->surface = surface;
	}

	void ObjectNodeContent::FreeContent()
	{
		if( surface.get() )
		{
			SDL_FreeSurface( surface.get()->GetSdlSurface() );
		}
		surface = nullptr;
	}
}