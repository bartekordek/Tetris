#pragma once

#include <string>
#include "IObservableData.h"

namespace Moge
{
    class IKeyboardData: public IObservableData
    {
    public:
        IKeyboardData() = default;
        virtual ~IKeyboardData() = default;
        MogeLib_API virtual void setKeyName( const std::string& keyName ) = 0;
        MogeLib_API virtual const std::string& getKeyName()const = 0;
        MogeLib_API virtual void setKeyIsDown( const bool keyIsDown ) = 0;
        MogeLib_API virtual const bool getKeyIsDown()const = 0;
    protected:
    private:
    };
}