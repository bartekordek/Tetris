#include "Position.h"

namespace MOGE
{
	Position::Position()
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
	}

	void Position::SetY( CInt y )
	{
		mY = y;
	}

	void Position::Set( CInt x, CInt y )
	{
		mX = x;
		mY = y;
	}
}