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
				const Type z = static_cast<Type>( 0 ) ): IPosition(), MultiPoint( 3 )
			{
				MultiPoint<Type>::setValue( Axes::X, x );
				MultiPoint<Type>::setValue( Axes::Y, y );
				MultiPoint<Type>::setValue( Axes::Z, z );
			}

			virtual ~IPositionAdapter()
			{
			}

			virtual const Type getX()const
			{
				return MultiPoint<Type>::getValue( Axes::X );
			}

			virtual const Type getY()const
			{
				return MultiPoint<Type>::getValue( Axes::Y );
			}

			virtual const Type getZ()const
			{
				return MultiPoint<Type>::getValue( Axes::Z );
			}
			
			virtual void setXyz( const Type x, const Type y, const Type z )
			{
				MultiPoint<Type>::setValue( Axes::X, x );
				MultiPoint<Type>::setValue( Axes::Y, y );
				MultiPoint<Type>::setValue( Axes::Z, z );
			}

			virtual void setXyz( const IPosition& pos )
			{
				MultiPoint<Type>::setValue( Axes::X, pos.getX() );
				MultiPoint<Type>::setValue( Axes::Y, pos.getY() );
				MultiPoint<Type>::setValue( Axes::Z, pos.getZ() );
			}

			virtual void setX( const Type x )
			{
				MultiPoint<Type>::setValue( Axes::X, x );
			}

			virtual void setY( const Type y )
			{
				MultiPoint<Type>::setValue( Axes::Y, y );
			}

			virtual void setZ( const Type z )
			{
				MultiPoint<Type>::setValue( Axes::Z, z );
			}

		protected:
		private:
		};
	}
}