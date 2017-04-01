#pragma once
#include "Math/IPosition.h"
namespace Moge
{
	namespace Math
	{
		class MogeLib_API IPositionFactory
		{
		public:
			static IPosition<double>* createPositionDouble1D();
			static IPosition<double>* createPositionDouble2D();
			static IPosition<double>* createPositionDouble3D();

			static IPosition<int>* createPositionInt1D();
			static IPosition<int>* createPositionInt2D( const int v1d = 0, const int v2d = 0 );
			static IPosition<int>* createPositionInt3D();

			static IPosition<unsigned int>* createPositionUInt1D();
			static IPosition<unsigned int>* createPositionUInt2D();
			static IPosition<unsigned int>* createPositionUInt3D();

			static IPosition<double>* createSimplePositionDouble3D();
		};
	}
}