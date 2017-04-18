#pragma once
#include <MogeLib.h>
namespace Moge
{
	namespace Math
	{
		class MogeLib_API Epsilon
		{
		public:
			void setEpsilon( const double epislon )
			{
				this->epsilon = epislon;
			}

			const double getEpsilon()const
			{
				return this->epsilon;
			}
		protected:
		private:
			double epsilon = 0.00000001; //TODO: Think about default value;
		};
	}
}