#include "IKeyboardObservableImp.h"
#include "IKeyboardObserver.h"

namespace Moge
{
    void IKeyboardObservableImp::notifyKeyboardObservers( IKey* data )
    {
        for( IKeyboardObserver* observer : this->observers )
        {
            observer->keyboardEvent( data );
        }
    }

    void IKeyboardObservableImp::registerObserver( IKeyboardObserver* observer )
    {
        this->observers.insert( observer );
    }

    void IKeyboardObservableImp::unregisterObserver( IKeyboardObserver* observer )
    {
        this->observers.erase( observer );
    }
}