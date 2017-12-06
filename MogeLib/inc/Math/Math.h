#pragma once
#include <MogeLib.h>
namespace Moge
{
    namespace Math
    {
        namespace Util
        {
            template<typename Type>
            Type MogeLib_API abs( const Type arg )
            {
                if( arg < 0 )
                {
                    return 0 - arg;
                }
                return arg;
            }
        }
    }
}