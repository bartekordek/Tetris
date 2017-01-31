#include "IKeyboardObservable.h"
#include "IKeyboardObserver.h"

namespace Moge
{
	void IKeyboardObservable::notifyObservers( IObservableData* data )
	{
		for( IObserver* observer: this->observers )
		{
			IKeyboardObserver* keyboardObserver = static_cast<IKeyboardObserver*>( observer );
			keyboardObserver->keyboardEvent( data );
		}
	}
}
