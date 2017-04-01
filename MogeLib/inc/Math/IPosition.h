#pragma once
#include "MogeLib.h"
namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class MogeLib_API IPosition
		{
		public:
			IPosition()
			{
			}

			virtual ~IPosition()
			{
			}

			virtual const Type getX()const = 0;
			virtual const Type getY()const = 0;
			virtual const Type getZ()const = 0;

			virtual void setX( const Type x ) = 0;
			virtual void setY( const Type y ) = 0;
			virtual void setZ( const Type z ) = 0;
			void setXyz( const Type x, const Type y, const Type z )
			{
				setX( x );
				setY( y );
				setZ( z );
			}

			void setXyz( const IPosition& object )
			{
				setX( object.getX() );
				setY( object.getY() );
				setZ( object.getZ() );
			}

		protected:
		private:
		};
	}
}