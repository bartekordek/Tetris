#pragma once
#include "Math/Epsilon.h"
namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class MogeLib_API Vector3D: public Epsilon<Type>
		{
		public:
			Vector3D() = default;
			Vector3D( const Type x, const Type y, const Type z ):
				x(x), 
				y(y),
				z(z)
			{
			}

			virtual ~Vector3D() = default;

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

			void setXYZ( const Type x, const Type y, const Type z )
			{
				this->x = x;
				this->y = y;
				this->z = z;
			}

			void setXYZ( const Vector3D& object )
			{
				this->x = object.x;
				this->y = object.y;
				this->z = object.z;
			}

			const bool operator==( const Vector3D& ivector )const
			{
				if( 
					Epsilon<Type>::equals( this->x, ivector.x ) &&
					Epsilon<Type>::equals( this->y, ivector.y ) &&
					Epsilon<Type>::equals( this->z, ivector.z ) )
				{
					return true;
				}
				return false;
			}

			Vector3D<Type> operator*( const Vector3D<Type>& right )const
			{
				Vector3D<Type> result;
				result.x = this->x * right.x;
				result.y = this->y * right.y;
				result.z = this->z * right.z;
				return result;
			}

			Vector3D<Type>& operator=( const Vector3D<Type>& right )
			{
				if( this != &right )
				{
					this->x = right.x;
					this->y = right.y;
					this->z = right.z;
				}
				return *this;
			}
		protected:
			Type x = static_cast<Type>( 0 );
			Type y = static_cast<Type>( 0 );
			Type z = static_cast<Type>( 0 );
		};
	}
}
