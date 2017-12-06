#include "Math/IPositionFactory.h"
#include "Math/IPositionAdapter.h"
#include "Math/MultiPoint.h"
#include "Math/PositionDouble3D.h"

namespace Moge
{
    namespace Math
    {
        IPosition<double>* IPositionFactory::createPositionDouble1D()
        {
            MultiPoint<double> mp( 1 );
            auto result = new IPositionAdapter<double>( mp );
            return result;
        }

        IPosition<double>* IPositionFactory::createPositionDouble2D()
        {
            MultiPoint<double> mp( 2 );
            auto result = new IPositionAdapter<double>( mp );
            return result;
        }

        IPosition<double>* IPositionFactory::createPositionDouble3D()
        {
            MultiPoint<double> mp( 3 );
            auto result = new IPositionAdapter<double>( mp );
            return result;
        }

        IPosition<int>* IPositionFactory::createPositionInt1D()
        {
            MultiPoint<int> mp( 1 );
            auto result = new IPositionAdapter<int>( mp );
            return result;
        }

        IPosition<int>* IPositionFactory::createPositionInt2D( const int v1d, const int v2d )
        {
            MultiPoint<int> mp( 2 );
            auto result = new IPositionAdapter<int>( mp );
            result->setX( v1d );
            result->setY( v2d );
            return result;
        }

        IPosition<int>* IPositionFactory::createPositionInt3D()
        {
            MultiPoint<int> mp( 3 );
            auto result = new IPositionAdapter<int>( mp );
            return result;
        }

        IPosition<unsigned int>* IPositionFactory::createPositionUInt1D()
        {
            MultiPoint<unsigned int> mp( 1 );
            auto result = new IPositionAdapter<unsigned int>( mp );
            return result;
        }

        IPosition<unsigned int>* IPositionFactory::createPositionUInt2D()
        {
            MultiPoint<unsigned int> mp( 2 );
            auto result = new IPositionAdapter<unsigned int>( mp );
            return result;
        }

        IPosition<unsigned int>* IPositionFactory::createPositionUInt3D()
        {
            MultiPoint<unsigned int> mp( 3 );
            auto result = new IPositionAdapter<unsigned int>( mp );
            return result;
        }

        IPosition< double >* IPositionFactory::createSimplePositionDouble3D()
        {
            return new PositionDouble3D();
        }
    }
}