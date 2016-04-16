#include "Node.h"
//#include "Size.h"

namespace MOGE
{
	Node::Node(): Named(""), Position(0, 0), Size( 640, 480 )
	{
		//if( name.empty() )
		//{
		//	static unsigned int index = 0;
		//	Named::SetName( "Node:" + std::to_string( index++ ));
		//}
		//UpdateGeometrics();
	}

	Node::~Node()
	{
		//if( mImg.get()->hwdata )
		//{
		//	SDL_FreeSurface( mImg.get() );
		//}
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

	void Node::FreeCurrentImage()
	{
		/*if( mImg.get() )
		{
			if( mImg.get()->format )
			{
				SDL_FreeSurface( mImg.get() );
			}
		}*/
	}

	void Node::UpdateGeometrics()
	{
		//mGeometrics.x = static_cast<Sint16>( mPosition.GetX() );
		//mGeometrics.y = static_cast<Sint16>( mPosition.GetY() );
		//mGeometrics.w = static_cast<Uint16>( mSize.GetWidth() );
		//mGeometrics.h = static_cast<Uint16>( mSize.GetHeight() );
	}
}