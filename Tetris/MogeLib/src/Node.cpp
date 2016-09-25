#include "Node.h"
#include <SDL.h>

namespace Moge
{
	Node::Node( const MyString& name ): Name( name ), Math::IPosition<int>(), Math::ISize<unsigned int>()
	{
		this->mGeometrics = new SDL_Rect();
		if( Name::GetName().empty() )
		{
			static unsigned int index = 0;
			Name::SetName( "Node:" + std::to_string( index++ ) );
		}
		//UpdateGeometrics();
	}

	Node::~Node()
	{
		delete this->mGeometrics;
	}
	
	SDL_Rect* Node::GetGeometricsInfo()const
	{
		return mGeometrics;
	}

	void Node::UpdateGeometrics()
	{
		mGeometrics->x = static_cast<Sint16>( getX() );
		mGeometrics->y = static_cast<Sint16>( getY() );
		mGeometrics->w = static_cast<Uint16>( getWidth() );
		mGeometrics->h = static_cast<Uint16>( getHeight() );
	}
}