#pragma once

#include "Position.h"

namespace MOGE
{
	class MOGE_API Position3d: public Position
	{
	public:
		Position3d();
		Position3d( CInt x, CInt y, CInt z );
		Position3d( const Position3d& position );
		~Position3d();

		CInt GetZ()const;

	protected:
		virtual void UpdateImplementation();
	private:
		int mZ;
	};
}