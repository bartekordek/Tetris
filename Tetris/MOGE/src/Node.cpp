#include "Node.h"
#include "Size.h"

namespace MOGE
{
	Node::Node():
		mVisible( true )
	{
	}

	Node::Node( const Path& path, const Size& size ):
		mSize( size ),
		mFilePath( path ),
		mImg( nullptr )
	{

	}

	Node::Node( const Size& size, const Position& position ):
		mSize( size ),
		mPosition( position ),
		mImg( nullptr )
	{
	}

	Node::~Node()
	{
		SDL_FreeSurface( mImg.get() );
	}

	void Node::SetVisible( const bool visible )
	{
		mVisible = visible;
	}

	const bool Node::IsVisible()const
	{
		return mVisible;
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

	void Node::SetPath( const Path& path )
	{
		mFilePath = path;
	}

	const Path& Node::GetPath()const
	{
		return mFilePath;
	}

	void Node::SetSize( const Size& size )
	{
		mSize = size;
	}

	void Node::SetPosition( const Position& position )
	{
		mPosition = position;
	}

	const Position& Node::GetPosition()const
	{
		return mPosition;
	}

	const Size& Node::GetSize()const
	{
		return mSize;
	}

	SDL_Rect* Node::GetGeometricsInfo()
	{
		return &mGeometrics;
	}
}