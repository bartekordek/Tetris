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
				MultiPoint<Type>::setValue( Axes::X, x );
				MultiPoint<Type>::setValue( Axes::Y, y );
				MultiPoint<Type>::setValue( Axes::Z, z );
			}

			explicit IPositionAdapter( const MultiPoint<Type>& mp )
			{
				MultiPoint<Type>::operator=( mp );
			}

			virtual ~IPositionAdapter()
			{
			}

			IPosition<Type>& operator=( const IPosition<Type>& position )override
			{
				if( this != &position )
				{
					MultiPoint<Type>::setValue( Axes::X, position.getX() );
					MultiPoint<Type>::setValue( Axes::Y, position.getY() );
					MultiPoint<Type>::setValue( Axes::Z, position.getZ() );
				}
				return *this;
			}

			const Type getX()const override
			{
				return MultiPoint<Type>::getValue( Axes::X );
			}

			const Type getY()const override
			{
				return MultiPoint<Type>::getValue( Axes::Y );
			}

			const Type getZ()const override
			{
				return MultiPoint<Type>::getValue( Axes::Z );
			}
			
			void setXyz( const Type x, const Type y, const Type z ) override
			{
				MultiPoint<Type>::setValue( Axes::X, x );
				MultiPoint<Type>::setValue( Axes::Y, y );
				MultiPoint<Type>::setValue( Axes::Z, z );
			}

			void setX( const Type x ) override
			{
				MultiPoint<Type>::setValue( Axes::X, x );
			}

			void setY( const Type y ) override
			{
				MultiPoint<Type>::setValue( Axes::Y, y );
			}

			void setZ( const Type z ) override
			{
				MultiPoint<Type>::setValue( Axes::Z, z );
			}

		protected:
		private:
		};
	}
}