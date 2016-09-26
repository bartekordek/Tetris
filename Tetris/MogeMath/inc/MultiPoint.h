#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

namespace Moge
{
	namespace Math
	{
		enum class Axes: unsigned int
		{
			X = 0,
			Y,
			Z
		};

		template <typename Type>
		class MultiPoint
		{
		public:

			explicit MultiPoint( const unsigned int axisRows = 0 )
			{
				if( 0 != axisRows )
				{
					setAxesCount( axisRows );
				}
			}

			virtual ~MultiPoint()
			{
			}

			const Type distance( const std::shared_ptr<MultiPoint<Type>>& p )const
			{
				return this->distance( *p );
			}

			const Type distance( const MultiPoint<Type>& p )const
			{
				const unsigned axesCount = std::min( this->axisValue.size(), p.axisValue.size() );
				Type distanceSquare = static_cast<Type>( 0.0 );
				for( unsigned int i = 0; i < axesCount; ++i )
				{
					Type leftAxisValue = ( this->axisValue.at( i ) );
					Type rightAxisValue = ( p.axisValue.at( i ) );
					Type differencePerDimension = abs( leftAxisValue - rightAxisValue );
					Type squareOfCurrentDimension = ( differencePerDimension * differencePerDimension );
					distanceSquare += squareOfCurrentDimension;
				}
				return static_cast<Type>( sqrt( distanceSquare ) );
			}

			const MultiPoint<Type> operator+( const MultiPoint<Type>& p )const
			{
				const unsigned axesCount = std::max( this->axisValue.size(), p.axisValue.size() );
				const unsigned lowerAxesCount = std::min( this->axisValue.size(), p.axisValue.size() );
				MultiPoint<Type> result( axesCount );
				for( unsigned int i = 0; i < lowerAxesCount; ++i )
				{
					result.axisValue[i] = this->axisValue[i] + p.axisValue[i];
				}
				return result;
			}

			MultiPoint<Type> operator-( const MultiPoint<Type>& p )const
			{
				const unsigned axesCount = std::max( this->axisValue.size(), p.axisValue.size() );
				const unsigned lowerAxesCount = std::min( this->axisValue.size(), p.axisValue.size() );
				MultiPoint<Type> result( axesCount );
				for( unsigned int i = 0; i < lowerAxesCount; ++i )
				{
					result.axisValue[i] = this->axisValue[i] - p.axisValue[i];
				}
				return result;
			}

			MultiPoint<Type> relativeDistance( const MultiPoint<Type>& right )const
			{
				const unsigned int axisCount = this->axisValue.size();
				const unsigned int pAxisCount = right.axisValue.size();
				const unsigned int targetAxisCount = std::max( axisCount, pAxisCount );
				MultiPoint<Type> result( targetAxisCount );
				for( unsigned int axisIndex = 0; axisIndex < targetAxisCount; ++axisIndex )
				{
					result.setValue( axisIndex, std::abs( this->getValue( axisIndex ) - right.getValue( axisIndex ) ) );
				}
				return result;
			}

			MultiPoint<Type>& operator=( const MultiPoint<Type>& right )
			{
				if( this != &right )
				{
					const unsigned int pAxisCount = right.axisValue.size();
					this->setAxesCount( pAxisCount );

					for( unsigned int axisIndex = 0; axisIndex < pAxisCount; ++axisIndex )
					{
						this->setValue( axisIndex, right.getValue( axisIndex ) );
					}
				}
				return *this;
			}

			MultiPoint<Type> operator*( const MultiPoint<Type>& p )const
			{
				const unsigned axesCount = std::max( this->axisValue.size(), p.axisValue.size() );
				const unsigned lowerAxesCount = std::min( this->axisValue.size(), p.axisValue.size() );
				MultiPoint<Type> result( axesCount );
				for( unsigned int i = 0; i < lowerAxesCount; ++i )
				{
					Type& leftAxisValue = *( this->axisValue[i] );
					Type& rightAxisValue = *( p.axisValue[i] );
					result.setValue( leftAxisValue * rightAxisValue );
				}
				return result;
			}

			const bool operator==( const MultiPoint<Type>& p )const
			{
				if( this == &p )
				{
					return true;
				}

				const unsigned int axisCount = this->axisValue.size();
				if( axisCount == p.axisValue.size() )
				{
					for( unsigned int i = 0; i < axisCount; ++i )
					{
						if( this->axisValue[i] != p.axisValue[i] )
						{
							return false;
						}
					}
					return true;
				}

				return false;
			}

			void setAxesCount( const unsigned int count )
			{
				axisValue.resize( count );
			}

			const unsigned int getAxesCount()const
			{
				return this->axisValue.size();
			}

			const Type getValue( const Axes axisIndex )const
			{
				return axisValue.at( static_cast<unsigned int>( axisIndex ) );
			}

			const Type getValue( const unsigned int axisIndex )const
			{
				return axisValue.at( static_cast<unsigned int>( axisIndex ) );
			}

			void setValue( const Axes axisIndex, const Type value )
			{
				this->axisValue.at( static_cast<unsigned int>( axisIndex ) ) = value;
			}

			void setValue( const unsigned int axisIndex, const Type value )
			{
				this->axisValue.at( static_cast<unsigned int>( axisIndex ) ) = value;
			}

			const Type distanceToZeroZero()const
			{
				Type distanceToZeroZero = static_cast<Type>( 0.0 );
				for( auto& axisValue : this->axisValue )
				{
					distanceToZeroZero += axisValue*axisValue;
				}
				return sqrt( distanceToZeroZero );
			}

		private:
			std::vector<Type> axisValue;
		};
	}
}