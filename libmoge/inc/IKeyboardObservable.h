#pragma once
#include "IKeyboardObserver.h"
#include <map>
#include <memory>

namespace Moge
{
    using KeyMap = std::map<std::string, std::shared_ptr<IKey>>;
    class MogeLib_API IKeyboardObservable
    {
    public:
        IKeyboardObservable();
        IKeyboardObservable( const IKeyboardObservable& r ) = delete;
        virtual ~IKeyboardObservable();
        virtual void notifyKeyboardObservers( const IKey& data );

        virtual void registerKeyboardObserver( IKeyboardObserver* observer ) = 0;
        virtual void unregisterKeyboardObserver( IKeyboardObserver* observer ) = 0;

    protected:
    private:

    };
}