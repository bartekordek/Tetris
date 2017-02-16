#include "IKeyboardObservable.h"
#include "IKeyboardObserver.h"
#include "IKeyboardObservableImp.h"

namespace Moge
{
	IKeyboardObservable::IKeyboardObservable()
	{
		this->impl =  new IKeyboardObservableImp();
	}

	IKeyboardObservable::~IKeyboardObservable()
	{
		delete this->impl;
	}

	void IKeyboardObservable::notifyKeyboardObservers( IKey* data )
	{
		this->impl->notifyKeyboardObservers( data );
	}

    void IKeyboardObservable::registerObserver( IKeyboardObserver* observer )
    {
		this->impl->registerObserver( observer );
    }

    void IKeyboardObservable::unregisterObserver( IKeyboardObserver* observer )
    {
        this->impl->unregisterObserver( observer );
    }
}