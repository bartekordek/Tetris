#include "Math/SizeDouble3D.h"
namespace Moge
{
	namespace Math
	{
		void SizeDouble3D::setWidth( const double width )
		{
			this->width = width;
		}

		void SizeDouble3D::setHeight( const double height )
		{
			this->height = height;
		}

		void SizeDouble3D::setDepth( const double depth )
		{
			this->depth = depth;
		}

		const double SizeDouble3D::getWidth()const
		{
			return this->width;
		}

		const double SizeDouble3D::getHeight()const
		{
			return this->height;
		}

		const double SizeDouble3D::getDepth()const
		{
			return this->depth;
		}
	}
}