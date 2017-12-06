#include "Math/SizeDouble2D.h"
namespace Moge
{
    namespace Math
    {
        void SizeDouble2D::setWidth( const double widthVal )
        {
            this->width = widthVal;
        }

        void SizeDouble2D::setHeight( const double heightVal )
        {
            this->height = heightVal;
        }

#if _MSC_VER
        __pragma( warning( push ) ) \
        __pragma( warning( disable:4100 ) )
#endif
        void SizeDouble2D::setDepth( const double depthVal )
        {
        }

#if _MSC_VER
        __pragma( warning( pop ) )
#endif
        const double SizeDouble2D::getWidth()const
        {
            return this->width;
        }

        const double SizeDouble2D::getHeight()const
        {
            return this->height;
        }

        const double SizeDouble2D::getDepth()const
        {
            return 0.0f;
        }
    }
}