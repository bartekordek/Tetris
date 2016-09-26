#pragma once

#include "Point2D.h"

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class Point3D: public Point2D<Type>
		{
		public:
			Point3D( 
				const Type x = static_cast<Type>( 0 ), 
				const Type y = static_cast<Type>( 0 ),
				const Type z = static_cast<Type>( 0 ) ): Point2D( x, y ), z(z)
			{
			}

			Point3D( const Point3D& argument ): Point2D( x, y ), z( z )
			{
			}

			virtual ~Point3D()
			{
			}

			Point3D& operator=( const Point3D& right )
			{
				if( &right != this )
				{
					Point1D::setX( right::getX() );
					Point2D::setY( right::getY() );
					this->z = right.z;
				}
				return *this;
			}

			void setZ( const Type z )
			{
				this->z = z;
			}

			const Type getY()const
			{
				return this->y;
			}

			const bool operator==( const Point3D& right )const
			{
				return Point2D::operator==( right ) && right.z == this->z;
			}

			const Point3D operator+( const Point3D& right )const
			{
				return Point3D( this->getX() + right.getX(), this->getY() + right.getY(), this->z + right.z );
			}

			const Point3D operator-( const Point3D& right )const
			{
				return Point3D( this->getX() - right.getX(), this->getY() - right.getY(), this->z - right.z );
			}

		protected:
			Type z = static_cast<Type>( 0 );

		private:
		};
	}
}