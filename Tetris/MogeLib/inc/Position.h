#pragma once

#include "GeneralUtilities.h"

namespace MOGE
{
	class Position
	{
	public:
		Position();
		Position( CInt x, CInt y );
		Position( const Position& position );
		virtual ~Position();

		Position& operator=( const Position& position );

		CInt GetX()const;
		CInt GetY()const;

		void SetX( CInt x );
		void SetY( CInt y );
		void Set( CInt x, CInt y );

	protected:
	private:
		int mX;
		int mY;
	};
}