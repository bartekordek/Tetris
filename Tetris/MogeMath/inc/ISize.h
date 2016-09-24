#pragma once

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class ISize
		{
		public:
			ISize()
			{
			}

			virtual ~ISize()
			{
			}

			virtual void setSize( const Type width, const Type height, const Type depth ) = 0;
			virtual void setWidth( const Type width ) = 0;
			virtual void setHeight( const Type height ) = 0;
			virtual void setHepth( const Type depth ) = 0;
			virtual void setSize( const ISize& size ) = 0;

			virtual const Type getWidth()const = 0;
			virtual const Type getHeight()const = 0;
			virtual const Type getDepth()const = 0;

		protected:
		private:
		};
	}
}