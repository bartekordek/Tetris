#pragma once

#include "MogeLib.h"

namespace Moge
{
    class IKeyboardObserver;
    class IKey;
	class IKeyboardObservableImp;
	class MogeLib_API IKeyboardObservable
	{
	public:
		IKeyboardObservable();
		virtual ~IKeyboardObservable();
		virtual void notifyKeyboardObservers( IKey* data = nullptr );

		virtual void registerObserver( IKeyboardObserver* observer );
		virtual void unregisterObserver( IKeyboardObserver* observer );

	protected:
	private:
		IKeyboardObservableImp* impl = nullptr;
	};
}