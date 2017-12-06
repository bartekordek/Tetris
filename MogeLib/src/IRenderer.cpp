#include "IRenderer.h"

namespace Moge
{
    ColorS convertE2S( const ColorE c )
    {
        ColorS result;
        if( ColorE::WHITE == c )
        {
            result.r = result.g = result.b = 255;
        }
        else if( ColorE::RED == c )
        {
            result.r = 255;
            result.g = 0;
            result.b = 0;
        }
        else if( ColorE::GREEN == c )
        {
            result.r = 0;
            result.g = 255;
            result.b = 0;
        }
        else if( ColorE::BLUE == c )
        {
            result.r = 0;
            result.g = 0;
            result.b = 255;
        }
        result.alpha = 255;
        return result;
    }
}