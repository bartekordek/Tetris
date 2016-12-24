#include "IObservable.h"
#include "IObservableImpl.h"

namespace Moge
{
	IObservable::IObservable(): impl( new IObservableImpl() )
	{
	}

	IObservable::~IObservable()
	{
		delete this->impl;
	}

	void IObservable::registerObserver( IObserver* observer )
	{
		
	}

}