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
        virtual void setKeyName( const std::string& keyName ) = 0;
        virtual const std::string& getKeyName()const = 0;
        virtual const bool getKeyIsDown()const = 0;
        virtual void setKeyIsDown( const bool isDown ) = 0;
    protected:
    private:

    };
}