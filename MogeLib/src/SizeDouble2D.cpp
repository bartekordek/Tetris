#include "Math/SizeDouble2D.h"
namespace Moge
{
	namespace Math
	{
		void SizeDouble2D::setWidth( const double width )
		{
			this->width = width;
		}

		void SizeDouble2D::setHeight( const double height )
		{
			this->height = height;
		}

		void SizeDouble2D::setDepth( const double depth )
		{
		}

		const double SizeDouble2D::getWidth()const
		{
			return this->width;
		}

		const double SizeDouble2D::getHeight()const
		{
			return this->height;
		}

		const double SizeDouble2D::getDepth()const
		{
			return 0.0f;
		}
	}
}