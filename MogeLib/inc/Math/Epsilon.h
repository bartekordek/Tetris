#pragma once
#include <MogeLib.h>
#include "Math.h"
#include <type_traits>

namespace Moge
{
	namespace Math
	{
		template <typename Type>
		class MogeLib_API Epsilon
		{
		public:
			Epsilon()
			{
#if _MSC_VER
				__pragma( warning( push ) ) \
					__pragma( warning( disable:4127 ) )
#endif
				if(
					static_cast<const bool>( std::is_same<Type, float>::value ) || 
					static_cast<const bool>( std::is_same<Type, double>::value ) )
				{
					this->epsilon = static_cast<Type>( 0.0000000001 );
				}
#if _MSC_VER
				__pragma( warning( pop ) )
#endif
			}

			virtual ~Epsilon() = default;

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
				return Util::abs( val1 - val2 ) <= epsilonAsType;
			}
		private:
			Type epsilon = static_cast<Type>( 0 );
		};
	}
}