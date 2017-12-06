#pragma once
#include "Epsilon.h"
namespace Moge
{
    namespace Math
    {
        template <typename Type>
        class MogeLib_API IPosition: public Epsilon<Type>
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

            void setXyz( const IPosition<Type>& object )
            {
                setX( object.getX() );
                setY( object.getY() );
                setZ( object.getZ() );
            }

            virtual const bool operator==( const IPosition<Type>& position )const = 0;
            IPosition<Type>& operator=( const IPosition<Type>& right )
            {
                if( &right != this )
                {
                    setX( right.getX() );
                    setY( right.getY() );
                    setZ( right.getZ() );
                }
                return *this;
            }

        protected:
        private:
            
        };
    }
}