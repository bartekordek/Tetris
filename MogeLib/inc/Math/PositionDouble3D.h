#pragma once
#include "Math/IPosition.h"
#include <valarray>
namespace Moge
{
    namespace Math
    {
        class PositionDouble3D: public IPosition<double>
        {
        public:
            PositionDouble3D() = default;
            virtual ~PositionDouble3D() = default;

            PositionDouble3D& operator=( const PositionDouble3D& right ) = default;

            const double getX( void ) const override;
            const double getY( void ) const override;
            const double getZ( void ) const override;

            void setX( const double x )override;
            void setY( const double y )override;
            void setZ( const double z )override;

            const bool operator==( const IPosition<double>& position )const override
            {
                if( 
                    std::abs( this->x - position.getX() ) < this->getEpsilon() &&
                    std::abs( this->y - position.getY() ) < this->getEpsilon() &&
                    std::abs( this->z - position.getZ() ) < this->getEpsilon() )
                {
                    return true;
                }
                return false;
            }

        protected:
        private:
            double x = 0.0;
            double y = 0.0;
            double z = 0.0;
        };
    }
}