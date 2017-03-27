#pragma once
#include "Math/IPosition.h"
namespace Moge
{
	namespace Math
	{
		class PositionDouble2D: public IPosition<double>
		{
		public:
			PositionDouble2D() = default;
			virtual ~PositionDouble2D() = default;

			PositionDouble2D& operator=( const PositionDouble2D& right ) = default;

			const double getX( void ) const override;
			const double getY( void ) const override;
			const double getZ( void ) const override;

			void setX( const double x )override;
			void setY( const double y )override;
			void setZ( const double z )override;

		protected:
		private:
			double x = 0.0;
			double y = 0.0;
		};
	}
}