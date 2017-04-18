#include "Math\Vector3DFactory.h"
#include "Vector3DSimple.h"

namespace Moge
{
	namespace Math
	{
		IVector3D< double >* Vector3DFactory::createVectorSimpleDouble( const double x, const double y, const double z )
		{
			IVector3D< double >* result = new Vector3DSimple<double>( x, y, z );
			return result;
		}

		IVector3D< int >* Vector3DFactory::createVectorSimpleInt( const int x, const int y, const int z )
		{
			IVector3D< int >* result = new Vector3DSimple<int>( x, y, z );
			return result;
		}

		IVector3D< unsigned int >* Vector3DFactory::createVectorSimpleUInt( const unsigned int x, const unsigned int y, const unsigned int z )
		{
			IVector3D< unsigned int >* result = new Vector3DSimple<unsigned int>( x, y, z );
			return result;
		}
	}
}