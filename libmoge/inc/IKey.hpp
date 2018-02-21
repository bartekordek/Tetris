#pragma once

#include "MogeLib.h"
#include <string>

namespace Moge
{
    class MogeLib_API IKey
    {
    public:
        IKey( void );
        virtual ~IKey( void );
        virtual const std::string& getKeyName()const = 0;
        virtual const bool getKeyIsDown()const = 0;
    protected:
    private:

    };
}