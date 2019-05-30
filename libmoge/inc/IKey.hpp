#pragma once

#include "MogeLib.h"
#include "CUL/MyString.hpp"

namespace Moge
{
    class MogeLib_API IKey
    {
    public:
        IKey( void );
        virtual ~IKey( void );
        virtual CUL::CnstMyStr& getKeyName()const = 0;
        virtual const bool getKeyIsDown()const = 0;
    protected:
    private:

    };
}