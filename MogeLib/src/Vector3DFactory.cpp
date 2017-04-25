#include "Math\Vector3DFactory.h"

namespace Moge
{
	namespace Math
	{
		Vector3D< double >* Vector3DFactory::createVectorSimpleDouble( const double x, const double y, const double z )
		{
			Vector3D< double >* result = new Vector3D<double>( x, y, z );
			return result;
		}

		Vector3D< int >* Vector3DFactory::createVectorSimpleInt( const int x, const int y, const int z )
		{
			Vector3D< int >* result = new Vector3D<int>( x, y, z );
			return result;
		}

		Vector3D< unsigned int >* Vector3DFactory::createVectorSimpleUInt( const unsigned int x, const unsigned int y, const unsigned int z )
		{
			Vector3D< unsigned int >* result = new Vector3D<unsigned int>( x, y, z );
			return result;
		}
	}
}