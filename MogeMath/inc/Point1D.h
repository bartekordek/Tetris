#pragma once

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class Point1D
		{
		public:
			Point1D( const Type argument = static_cast<Type>( 0 ) ): x( argument )
			{
			}

			Point1D( const Point1D& argument ): x( argument.x )
			{
			}

			virtual ~Point1D()
			{
			}

			Point1D& operator=( const Point1D& right )
			{
				if( &right != this )
				{
					this->x = right.x;
				}
				return *this;
			}

			void setX( const Type x )
			{
				this->x = x;
			}

			const Type getX()const
			{
				return this->x;
			}

			const bool operator==( const Point1D& right )const
			{
				return ( right.x == this->x );
			}

			const Point1D operator+( const Point1D& right )const
			{
				return Point1D( this->x + right.x );
			}

			const Point1D operator-( const Point1D& right )const
			{
				return Point1D( this->x - right.x );
			}

		protected:
			Type x = static_cast<Type>( 0 );
		private:
		};
	}
}