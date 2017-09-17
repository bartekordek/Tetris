#include "Math\PositionDouble2D.h"

namespace Moge
{
	namespace Math
	{
		const double PositionDouble2D::getX( void ) const
		{
			return this->x;
		}

		const double PositionDouble2D::getY( void ) const
		{
			return this->y;
		}

		const double PositionDouble2D::getZ( void ) const
		{
			return 0.0;
		}

		void PositionDouble2D::setX( const double xVal )
		{
			this->x = xVal;
		}

		void PositionDouble2D::setY( const double yVal )
		{
			this->y = yVal;
		}
		__pragma( warning( push ) ) \
		__pragma( warning( disable:4100 ) )
		void PositionDouble2D::setZ( const double zVal )
		{
		}
		__pragma( warning( pop ) )
	}
}