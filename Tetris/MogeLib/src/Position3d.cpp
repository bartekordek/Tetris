#include "Position3d.h"

namespace MOGE
{
	Position3d::Position3d(): Position( 0, 0 ), mZ( 0 )
	{

	}
	Position3d::Position3d(CInt x, CInt y, CInt z): Position(x, y), mZ(z)
	{

	}

	Position3d::Position3d( const Position3d& position )
	{
		if( this != &position )
		{
			Position::SetXY( position.GetX(), position.GetY() );
			this->mZ = position.mZ;
		}
	}


	Position3d::~Position3d()
	{
	}

	CInt Position3d::GetZ()const
	{
		return mZ;
	}

	void Position3d::UpdateImplementation()
	{

	}
}