#pragma once 

#include "IKey.hpp"

namespace Moge
{
    class MogeLib_API IKeyboardObserver
    {
    public:
        IKeyboardObserver() = default;
        virtual ~IKeyboardObserver() = default;
        virtual void onKeyboardEvent( const IKey& data ) = 0;
    protected:
    private:
    };
}