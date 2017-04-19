#pragma once

#include "Math/IVector3D.h"
#include "Math/Math.h"

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

			const Type getX()const override
			{
				return this->x;
			}
			const Type getY()const override
			{
				return this->y;
			}
			const Type getZ()const override
			{
				return this->z;
			}

			void setX( const Type x ) override
			{
				this->x = x;
			}
			void setY( const Type y ) override
			{
				this->y = y;
			}
			void setZ( const Type z ) override
			{
				this->z = z;
			}

			const bool operator==( const IVector3D<Type>& position )const override
			{
				if(
					Util::abs( this->x - position.getX() ) < this->getEpsilon() &&
					Util::abs( this->y - position.getY() ) < this->getEpsilon() &&
					Util::abs( this->z - position.getZ() ) < this->getEpsilon() )
				{
					return true;
				}
				return false;
			}

			IVector3D<Type>& operator*( const IVector3D<Type>& right ) override
			{
				this->x *= right.getX();
				this->y *= right.getY();
				this->z *= right.getZ();
				return *this;
			}
		protected:
		private:
			Type x = static_cast<Type>( 0 );
			Type y = static_cast<Type>( 0 );
			Type z = static_cast<Type>( 0 );
		};
	}
}