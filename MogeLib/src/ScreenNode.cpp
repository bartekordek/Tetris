#include "ScreenNode.h"

#include <SDL.h>

namespace Moge
{
	ScreenNode::ScreenNode()
	{
	}

	ScreenNode::ScreenNode( const ScreenNode& screenNode ):
		mainScreen ( screenNode.mainScreen ),
		mainScreenSurface ( screenNode.mainScreenSurface ),
		position ( screenNode.position ),
		size ( screenNode.size )
	{
	}

	ScreenNode::~ScreenNode()
	{
	}

	const int ScreenNode::getX()const
	{
		return this->position.getValue( Math::Axes::X );
	}

	const int ScreenNode::getY()const 
	{
		return this->position.getValue( Math::Axes::Y );
	}
	const int ScreenNode::getZ()const 
	{
		return this->position.getValue( Math::Axes::Z );
	}

	void ScreenNode::setXyz( const int x, const int y, const int z )
	{
		this->position.setValue( Math::Axes::X, x );
		this->position.setValue( Math::Axes::Y, y );
		this->position.setValue( Math::Axes::Z, z );
	}

	void ScreenNode::setXyz( const IPosition& size )
	{
		this->position.setValue( Math::Axes::X, size.getX() );
		this->position.setValue( Math::Axes::Y, size.getY() );
		this->position.setValue( Math::Axes::Z, size.getZ() );
	}

	void ScreenNode::setX( const int x )
	{
		this->position.setValue( Math::Axes::X, x );
	}
	void ScreenNode::setY( const int y )
	{
		this->position.setValue( Math::Axes::Y, y );
	}
	void ScreenNode::setZ( const int z )
	{
		this->position.setValue( Math::Axes::Z, z );
	}

	void ScreenNode::setSize( const unsigned int width, const unsigned int height, const unsigned int depth )
	{
		this->position.setValue( Math::Axes::X, width );
		this->position.setValue( Math::Axes::Y, height );
		this->position.setValue( Math::Axes::Z, depth );
	}

	void ScreenNode::setWidth( const unsigned int width )
	{
		this->position.setValue( Math::Axes::X, width );
	}

	void ScreenNode::setHeight( const unsigned int height )
	{
		this->position.setValue( Math::Axes::Y, height );
	}

	void ScreenNode::setDepth( const unsigned int depth )
	{
		this->position.setValue( Math::Axes::Z, depth );
	}

	void ScreenNode::setSize( const ISize& size )
	{
		this->position.setValue( Math::Axes::X, size.getWidth() );
		this->position.setValue( Math::Axes::Y, size.getHeight() );
		this->position.setValue( Math::Axes::Z, size.getDepth() );
	}

	const unsigned int ScreenNode::getWidth()const
	{
		return this->size.getValue( Math::Axes::X );
	}

	const unsigned int ScreenNode::getHeight()const
	{
		return this->size.getValue( Math::Axes::Y );
	}

	const unsigned int ScreenNode::getDepth()const
	{
		return this->size.getValue( Math::Axes::Z );
	}

	void ScreenNode::initialize()
	{
		mainScreen = SDL_CreateWindow( GetName().c_str(), getX(), getY(), getWidth(), getHeight(), SDL_WINDOW_SHOWN );
		mainScreenSurface = SDL_GetWindowSurface( mainScreen );
	}

	SDL_Window* ScreenNode::GetScreen()const
	{
		return mainScreen;
	}

	SDL_Surface* ScreenNode::GetSdlSurface()const
	{
		return mainScreenSurface;
	}

	void ScreenNode::DestroyScreen()
	{
		FreeContent();
	}

	void ScreenNode::setResolution( const Math::MultiPoint<const unsigned int>& resolution )
	{
	}

	void ScreenNode::UpdateImplementation()
	{
	}

	void ScreenNode::FreeContent()
	{
		SDL_DestroyWindow( this->mainScreen );
	}
}