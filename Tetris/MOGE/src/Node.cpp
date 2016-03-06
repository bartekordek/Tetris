#include "Node.h"
#include "Size.h"

namespace MOGE
{
	Node::Node( const String& name, const Path& path, const Size& size, const Position& position ):
		mSize( size ),
		mPosition( position ),
		mFilePath( path ),
		mVisible( false ),
		mImg( nullptr )
	{
		if( name.empty() )
		{
			static unsigned int index = 0;
			mName = "Node:" + std::to_string( index++ );
		}
		UpdateGeometrics();
	}

	Node::~Node()
	{
		SDL_FreeSurface( mImg.get() );
	}

	void Node::SetImage( ImagePtr& image )
	{
		SDL_FreeSurface( mImg.get() );
		mImg = image;
		mSize.Set( mImg->w, mImg->h );
		UpdateGeometrics();
	}

	const ImagePtr& Node::GetImage()const
	{
		return mImg;
	}

	void Node::SetSize( const Size& size )
	{
		mSize = size;
		UpdateGeometrics();
	}

	const Size& Node::GetSize()const
	{
		return mSize;
	}

	void Node::SetPosition( const Position& position )
	{
		mPosition = position;
		UpdateGeometrics();
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

	void Node::UpdateGeometrics()
	{
		mGeometrics.x = static_cast<Sint16>( mPosition.GetX() );
		mGeometrics.y = static_cast<Sint16>( mPosition.GetY() );
		mGeometrics.w = static_cast<Uint16>( mSize.GetWidth() );
		mGeometrics.h = static_cast<Uint16>( mSize.GetHeight() );
	}
}