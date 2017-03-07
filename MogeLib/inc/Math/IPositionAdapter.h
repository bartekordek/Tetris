#pragma once

#include "IPosition.h"
#include "MultiPoint.h"

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class IPositionAdapter: public IPosition<Type>, private MultiPoint<Type>
		{
		public:
			IPositionAdapter( 
				const Type x = static_cast<Type>( 0 ), 
				const Type y = static_cast<Type>( 0 ),
				const Type z = static_cast<Type>( 0 ) ): IPosition<Type>(), MultiPoint<Type>( 3 )
			{
				MultiPoint<Type>::setValue( Axis::X, x );
				MultiPoint<Type>::setValue( Axis::Y, y );
				MultiPoint<Type>::setValue( Axis::Z, z );
			}

			explicit IPositionAdapter( const MultiPoint<Type>& mp )
			{
				MultiPoint<Type>::operator=( mp );
			}

			virtual ~IPositionAdapter()
			{
			}

			IPosition<Type>& operator=( const IPosition<Type>& position )
			{
				if( this != &position )
				{
					MultiPoint<Type>::setValue( Axis::X, position.getX() );
					MultiPoint<Type>::setValue( Axis::Y, position.getY() );
					MultiPoint<Type>::setValue( Axis::Z, position.getZ() );
				}
				return *this;
			}

			const Type getX()const override
			{
				return MultiPoint<Type>::getValue( Axis::X );
			}

			const Type getY()const override
			{
				return MultiPoint<Type>::getValue( Axis::Y );
			}

			const Type getZ()const override
			{
				return MultiPoint<Type>::getValue( Axis::Z );
			}
			
			void setX( const Type x ) override
			{
				MultiPoint<Type>::setValue( Axis::X, x );
			}

			void setY( const Type y ) override
			{
				MultiPoint<Type>::setValue( Axis::Y, y );
			}

			void setZ( const Type z ) override
			{
				MultiPoint<Type>::setValue( Axis::Z, z );
			}

		protected:
		private:
		};
	}
}
