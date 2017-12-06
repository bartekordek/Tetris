#pragma once
#include "Math/Epsilon.h"
#include "IPosition.h"

namespace Moge
{
    namespace Math
    {
        template <typename Type>
        class MogeLib_API Vector3D: public IPosition<Type>
        {
        public:
            Vector3D() = default;
            Vector3D( const Type x, const Type y, const Type z ):
                x(x), 
                y(y),
                z(z)
            {
            }

            Vector3D( const Vector3D<Type>& vector ) = default;

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

            void setX( const Type xVal )
            {
                this->x = xVal;
            }

            void setY( const Type yVal )
            {
                this->y = yVal;
            }

            void setZ( const Type zVal )
            {
                this->z = zVal;
            }

            void setXYZ( const Type xVal, const Type yVal, const Type zVal )
            {
                this->x = xVal;
                this->y = yVal;
                this->z = zVal;
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

            const bool operator==( const IPosition<Type>& position )const override
            {
                if(
                    Epsilon<Type>::equals( this->x, position.getX() ) &&
                    Epsilon<Type>::equals( this->y, position.getY() ) &&
                    Epsilon<Type>::equals( this->z, position.getZ() ) )
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
