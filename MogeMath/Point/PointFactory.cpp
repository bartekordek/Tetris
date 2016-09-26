#include "PointFactory.h"

namespace Moge
{
	namespace Math
	{
		Point2D<double> PointFactory::create2dPointDouble( const double x, const double y )
		{
			Point2D<double> result( x, y );
			return result;
		}

		Point2D<unsigned int> PointFactory::create2dPointUnsignedInt( const unsigned int x, const unsigned int y )
		{
			Point2D<unsigned int> result( x, y );
			return result;
		}
	}
}