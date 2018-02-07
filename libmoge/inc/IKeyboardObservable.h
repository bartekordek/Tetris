#pragma once
#include "MogeLib.h"
#include "IKey.hpp"
#include <map>
#include <memory>

namespace Moge
{
    class IKeyboardObserver;
    class IKeyboardObservableImp;
    using KeyMap = std::map<std::string, std::shared_ptr<IKey>>;
    class MogeLib_API IKeyboardObservable
    {
    public:
        IKeyboardObservable();
        IKeyboardObservable( const IKeyboardObservable& r ) = delete;
        virtual ~IKeyboardObservable();
        virtual void notifyKeyboardObservers( IKey* data = nullptr );

        virtual void registerObserver( IKeyboardObserver* observer );
        virtual void unregisterObserver( IKeyboardObserver* observer );

    protected:
    private:
        IKeyboardObservableImp* impl = nullptr;
    };
}