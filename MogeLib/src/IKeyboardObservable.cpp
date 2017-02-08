#include "IKeyboardObservable.h"
#include "IKeyboardObserver.h"

namespace Moge
{
	void IKeyboardObservable::notifyKeyboardObservers( IKey* data )
	{
		for( IObserver* observer: this->observers )
		{
			IKeyboardObserver* keyboardObserver = static_cast<IKeyboardObserver*>( observer );
			keyboardObserver->keyboardEvent( data );
		}
	}

    void IKeyboardObservable::registerObserver( IKeyboardObserver* observer )
    {
        this->observers.insert( observer );
    }

    void IKeyboardObservable::unregisterObserver( IKeyboardObserver* observer )
    {
        this->observers.erase( observer );
    }
}
