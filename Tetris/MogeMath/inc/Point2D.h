#pragma once

#include "Point1D.h"

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class Point2D: public Point1D<Type>
		{
		public:
			Point2D( const Type x = static_cast<Type>( 0 ), const Type y = static_cast<Type>( 0 ) ): Point1D( x ), y(y)
			{
			}

			Point2D( const Point2D& argument ): Point1D( argument ), y( argument.y )
			{
			}

			virtual ~Point2D()
			{
			}

			Point2D& operator=( const Point2D& right )
			{
				if( &right != this )
				{
					Point1D::setx( right::getY() );
					this->y = right.y;
				}
				return *this;
			}

			void setY( const Type y )
			{
				this->y = y;
			}

			const Type getY()const
			{
				return this->y;
			}

			const bool operator==( const Point2D& right )const
			{
				return Point1D::operator==( right ) && right.y == this->y;
			}

			const Point2D operator+( const Point2D& right )const
			{
				return Point2D( Point1D::getX() + right.getX(), this->y + right.y );
			}

			const Point2D operator-( const Point2D& right )const
			{
				return Point2D( Point1D::getX() - right.getX(), this->y - right.y );
			}

		protected:
			Type y = static_cast<Type>( 0 );

		private:
		};
	}
}