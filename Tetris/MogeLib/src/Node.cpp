#include "Node.h"
#include <SDL.h>

namespace MOGE
{
	Node::Node( const String& name ): Named( name ), Position( 0, 0 ), Size( 640, 480 )
	{
		if( Named::GetName().empty() )
		{
			static unsigned int index = 0;
			Named::SetName( "Node:" + std::to_string( index++ ) );
		}
		UpdateGeometrics();
	}

	Node::~Node()
	{
	}
	
	void Node::SetVisible( const bool visible )
	{
		mVisible = visible;
	}

	const bool Node::GetVisible()const
	{
		return mVisible;
	}

	SDL_Rect* Node::GetGeometricsInfo()
	{
		return &mGeometrics;
	}

	void Node::UpdateGeometrics()
	{
		mGeometrics.x = static_cast<Sint16>( Position::GetX() );
		mGeometrics.y = static_cast<Sint16>( Position::GetY() );
		mGeometrics.w = static_cast<Uint16>( Size::GetWidth() );
		mGeometrics.h = static_cast<Uint16>( Size::GetHeight() );
	}
}