#include "Math/SizeDouble3D.h"
namespace Moge
{
	namespace Math
	{
		void SizeDouble3D::setWidth( const double widthVal )
		{
			this->width = widthVal;
		}

		void SizeDouble3D::setHeight( const double heightVal )
		{
			this->height = heightVal;
		}

		void SizeDouble3D::setDepth( const double depthVal )
		{
			this->depth = depthVal;
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