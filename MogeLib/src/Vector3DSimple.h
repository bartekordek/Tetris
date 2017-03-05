#pragma once

#include "Math/IVector3D.h"

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class Vector3DSimple: public IVector3D<Type>
		{
		public:
			Vector3DSimple() = default;
			Vector3DSimple( const Vector3DSimple<Type>& vector ) = default;
			Vector3DSimple( const Type x, const Type y, const Type z ): x( x ), y( y ), z( z )
			{
				
			}
			virtual ~Vector3DSimple() = default;

			Vector3DSimple& operator=( const Vector3DSimple<Type>& vector ) = default;

			const Type getX()const
			{
				return this->x;
			}
			const Type getY()const
			{
				return this->y;
			}
			const Type getZ()const
			{
				return this->z;
			}

			void setX( const Type x )
			{
				this->x = x;
			}
			void setY( const Type y )
			{
				this->y = y;
			}
			void setZ( const Type z )
			{
				this->z = z;
			}
		protected:
		private:
			Type x = static_cast<Type>( 0 );
			Type y = static_cast<Type>( 0 );
			Type z = static_cast<Type>( 0 );
		};
	}
}