#include "PositionOLD.h"

namespace Moge
{
	Position::Position(): mX(0), mY(0)
	{
	}

	Position::Position( CInt x, CInt y ): 
		mX( x ),
		mY( y )
	{
	}

	Position::Position( const Position& position )
	{
		*this = position;
	}

	Position& Position::operator=( const Position& position )
	{
		if( this != &position )
		{
			mX = position.mX;
			mY = position.mY;
		}
		return *this;
	}

	Position::~Position()
	{
	}

	CInt Position::GetX()const
	{
		return mX;
	}

	CInt Position::GetY()const
	{
		return mY;
	}

	void Position::SetX( CInt x )
	{
		mX = x;
		UpdateImplementation();
	}

	void Position::SetY( CInt y )
	{
		mY = y;
		UpdateImplementation();
	}

	void Position::SetXY( CInt x, CInt y )
	{
		mX = x;
		mY = y;
		UpdateImplementation();
	}
}