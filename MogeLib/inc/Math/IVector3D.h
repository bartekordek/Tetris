#pragma once
#include "Math/Epsilon.h"
namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class MogeLib_API IVector3D: public Epsilon
		{
		public:
			IVector3D() = default;
			virtual ~IVector3D() = default;

			virtual const Type getX()const = 0;
			virtual const Type getY()const = 0;
			virtual const Type getZ()const = 0;

			virtual void setX( const Type x ) = 0;
			virtual void setY( const Type y ) = 0;
			virtual void setZ( const Type z ) = 0;
			void setXYZ( const Type x, const Type y, const Type z )
			{
				setX( x );
				setY( y );
				setZ( z );
			}

			void setXYZ( const IVector3D& object )
			{
				setX( object.getX() );
				setY( object.getY() );
				setZ( object.getZ() );
			}

			virtual const bool operator==( const IVector3D& ivector )const = 0;
		};
	}
}
