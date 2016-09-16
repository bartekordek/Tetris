#include "ObjectNode.h"

namespace MogeLib
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

	const ImageSurface& ObjectNodeContent::GetSurface()const
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
		Size::SetWH( surface->GetSdlSurface()->w, surface->GetSdlSurface()->h );
		Node::UpdateGeometrics();
	}

	void ObjectNodeContent::UpdateImplementation()
	{
		if( surface && surface->GetSdlSurface() )
		{
			Size::SetWH( surface->GetSdlSurface()->w, surface->GetSdlSurface()->h );
			Node::UpdateGeometrics();
		}
	}

	void ObjectNodeContent::FreeContent()
	{
	}
}