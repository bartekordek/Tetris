#include "ObjectNode.h"
#include "SDL_surface.h"

namespace Moge
{

	ObjectNodeContent::ObjectNodeContent(): mFilePath("")
	{
	}

	ObjectNodeContent::ObjectNodeContent( const Path& filePath ):mFilePath( filePath )
	{
	}

	const int ObjectNodeContent::getX()const
	{
		return this->position.getValue( Math::Axes::X );
	}

	const int ObjectNodeContent::getY()const
	{
		return this->position.getValue( Math::Axes::Y );
	}
	const int ObjectNodeContent::getZ()const
	{
		return this->position.getValue( Math::Axes::Z );
	}

	void ObjectNodeContent::setXyz( const int x, const int y, const int z )
	{
		this->position.setValue( Math::Axes::X, x );
		this->position.setValue( Math::Axes::Y, y );
		this->position.setValue( Math::Axes::Z, z );
	}

	void ObjectNodeContent::setXyz( const IPosition& size )
	{
		this->position.setValue( Math::Axes::X, size.getX() );
		this->position.setValue( Math::Axes::Y, size.getY() );
		this->position.setValue( Math::Axes::Z, size.getZ() );
	}

	void ObjectNodeContent::setX( const int x )
	{
		this->position.setValue( Math::Axes::X, x );
	}
	void ObjectNodeContent::setY( const int y )
	{
		this->position.setValue( Math::Axes::Y, y );
	}
	void ObjectNodeContent::setZ( const int z )
	{
		this->position.setValue( Math::Axes::Z, z );
	}

	void ObjectNodeContent::setSize( const unsigned int width, const unsigned int height, const unsigned int depth )
	{
		this->size.setValue( Math::Axes::X, width );
		this->size.setValue( Math::Axes::Y, height );
		this->size.setValue( Math::Axes::Z, depth );
	}

	void ObjectNodeContent::setSize( const ISize& size )
	{
		this->size.setValue( Math::Axes::X, size.getWidth() );
		this->size.setValue( Math::Axes::Y, size.getHeight() );
		this->size.setValue( Math::Axes::Z, size.getDepth() );
	}

	void ObjectNodeContent::setWidth( const unsigned int width )
	{
		this->size.setValue( Math::Axes::X, width );
	}

	void ObjectNodeContent::setHeight( const unsigned int height )
	{
		this->size.setValue( Math::Axes::Y, height );
	}

	void ObjectNodeContent::setHepth( const unsigned int depth )
	{
		this->size.setValue( Math::Axes::Z, depth );
	}

	const unsigned int ObjectNodeContent::getWidth()const
	{
		return this->size.getValue( Math::Axes::X );
	}

	const unsigned int ObjectNodeContent::getHeight()const
	{
		return this->size.getValue( Math::Axes::Y );
	}

	const unsigned int ObjectNodeContent::getDepth()const
	{
		return this->size.getValue( Math::Axes::Z );
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
		setWidth( surface->GetSdlSurface()->w );
		setHeight( surface->GetSdlSurface()->h );
		Node::UpdateGeometrics();
	}

	void ObjectNodeContent::UpdateImplementation()
	{
		if( surface && surface->GetSdlSurface() )
		{
			setWidth( surface->GetSdlSurface()->w );
			setHeight( surface->GetSdlSurface()->h );
			Node::UpdateGeometrics();
		}
	}

	void ObjectNodeContent::FreeContent()
	{
	}
}