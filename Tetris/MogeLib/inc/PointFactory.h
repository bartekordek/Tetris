#pragma once

namespace Moge
{
	class IPosition;

	enum class PositionTypes: unsigned int
	{
		double1D = 1,
		double2D,
		double3D,
		uInt1D,
		uInt2D,
		uInt3D,
		int1D,
		int2D,
		int3D
	};

	class PointFactory
	{
	public:
		IPosition* createPosition( const PositionTypes positionType );
		PointFactory();
		virtual ~PointFactory();
	};
}