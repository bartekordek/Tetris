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

		void PositionDouble2D::setX( const double x )
		{
			this->x = x;
		}

		void PositionDouble2D::setY( const double y )
		{
			this->y = y;
		}

		void PositionDouble2D::setZ( const double z )
		{
		}
	}
}