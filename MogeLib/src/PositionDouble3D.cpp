#include "Math\PositionDouble3D.h"

namespace Moge
{
	namespace Math
	{
		const double PositionDouble3D::getX( void ) const
		{
			return this->x;
		}

		const double PositionDouble3D::getY( void ) const
		{
			return this->y;
		}

		const double PositionDouble3D::getZ( void ) const
		{
			return this->z;
		}

		void PositionDouble3D::setX( const double x )
		{
			this->x = x;
		}

		void PositionDouble3D::setY( const double y )
		{
			this->y = y;
		}

		void PositionDouble3D::setZ( const double z )
		{
			this->z = z;
		}
	}
}