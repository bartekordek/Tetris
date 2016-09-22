#pragma once

#include "MultiPoint.h"

namespace Moge
{
	namespace Math
	{
		class MultiPointFactory
		{
		public:
			template <typename Type>
			static MultiPoint<Type> create2d( const Type x, const Type y )
			{
				MultiPoint<Type> result( 2 );
				result.setValue( Axes::X, x );
				result.setValue( Axes::Y, y );
				return result;
			}

			template <typename Type>
			static MultiPoint<Type> create3d( const Type x, const Type y, const Type z )
			{
				MultiPoint<Type> result( 3 );
				result.setValue( Axes::X, x );
				result.setValue( Axes::Y, y );
				result.setValue( Axes::Z, z );
				return result;
			}

		protected:
		private:
			MultiPointFactory() {}
			virtual ~MultiPointFactory() {}
		};
	}
}