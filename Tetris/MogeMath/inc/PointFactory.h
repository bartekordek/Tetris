#pragma once

#include "Point3D.h"
#include <memory>

namespace Moge
{
	namespace Math
	{
		class PointFactory
		{
		public:
			static Point2D<double> create2dPointDouble( const double x, const double y );
			static Point2D<unsigned int> create2dPointUnsignedInt( const unsigned int x, const unsigned int y );

			template <typename Type>
			static std::shared_ptr<Point<Type>> create2dPointSharedPtr( const Type x, const Type y )
			{
				return std::shared_ptr<Point<Type>>( create2dPointPtr( x, y ) );
			}

			template <typename Type>
			static Point<Type>* create2dPointPtr( const Type x, const Type y )
			{
				Point<Type>* result = new Point<Type>( 2 );
				result->setValue( Axes::X, x );
				result->setValue( Axes::Y, y );
				return result;
			}

			template <typename Type>
			static Point<Type> create3dPoint( const Type x, const Type y, const Type z )
			{
				Point<Type> result( 3 );
				result.setValue( Axes::X, x );
				result.setValue( Axes::Y, y );
				result.setValue( Axes::Z, z );
				return result;
			}

			template <typename Type>
			static std::shared_ptr<Point<Type>> create3dPointSharedPtr( const Type x, const Type y, const Type z )
			{
				return std::shared_ptr<Point<Type>>( create3dPointPtr( x, y, z ) );
			}

			template <typename Type>
			static Point<Type>* create3dPointPtr( const Type x, const Type y, const Type z )
			{
				Point<Type>* result = new Point<Type>( 3 );
				result->setValue( Axes::X, x );
				result->setValue( Axes::Y, y );
				result->setValue( Axes::Z, z );
				return result;
			}

		private:
			PointFactory()
			{
			}

			virtual ~PointFactory()
			{
			}
		};
	}
}