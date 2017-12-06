#include "IKeyboardObservableImp.h"
#include "IKeyboardObserver.h"

namespace Moge
{
    void IKeyboardObservableImp::notifyKeyboardObservers( IKey* data )
    {
        for( IObserver* observer : this->observers )
        {
            IKeyboardObserver* keyboardObserver = static_cast<IKeyboardObserver*>( observer );
            keyboardObserver->keyboardEvent( data );
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