#pragma once

#include <MOGE.h>
#include "Aliases.h"

namespace MOGE
{
	class MOGE_API Position
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
		void SetXY( CInt x, CInt y );

	protected:
		virtual void UpdateImplementation() = 0;

	private:
		int mX;
		int mY;
	};
}