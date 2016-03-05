#include "Node.h"
#include "Size.h"

namespace MOGE
{
	Node::Node( const String& name, const Path& path, const Size& size, const Position& position ):
		mSize( size ),
		mPosition( position ),
		mVisible( false ),
		mImg( nullptr )
	{
		if( name.empty() )
		{
			static unsigned int index = 0;
			mName = "Node:" + std::to_string( index++ );
		}
	}

	Node::~Node()
	{
		SDL_FreeSurface( mImg.get() );
	}

	void Node::SetImage( ImagePtr& image )
	{
		SDL_FreeSurface( mImg.get() );
		mImg = image;

		mGeometrics.h = static_cast<Uint16> ( mImg->h );
		mGeometrics.w = static_cast<Uint16> ( mImg->w );
		mSize.Set( mGeometrics.w, mGeometrics.h );
	}

	const ImagePtr& Node::GetImage()const
	{
		return mImg;
	}

	void Node::SetSize( const Size& size )
	{
		mSize = size;
	}

	const Size& Node::GetSize()const
	{
		return mSize;
	}

	void Node::SetPosition( const Position& position )
	{
		mPosition = position;
	}

	const Position& Node::GetPosition()const
	{
		return mPosition;
	}

	void Node::SetVisible( const bool visible )
	{
		mVisible = visible;
	}

	const bool Node::GetVisible()const
	{
		return mVisible;
	}

	void Node::SetPath( const Path& path )
	{
		mFilePath = path;
	}

	const Path& Node::GetPath()const
	{
		return mFilePath;
	}

	void Node::SetName( const String& name )
	{
		mName = name;
	}

	const String& Node::GetName()const
	{
		return mName;
	}

	SDL_Rect* Node::GetGeometricsInfo()
	{
		return &mGeometrics;
	}
}