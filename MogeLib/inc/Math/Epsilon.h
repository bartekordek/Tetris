#pragma once
#include <MogeLib.h>
namespace Moge
{
	namespace Math
	{
		template <typename Type>
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
			const bool equals( const Type val1, const Type val2 )const
			{
				const Type epsilonAsType = static_cast<Type>( epsilon );
				return abs( val1 - val2 ) <= epsilonAsType;
			}
		private:
			double epsilon = 0.00000001; //TODO: Think about default value;
		};
	}
}