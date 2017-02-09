#pragma once

#include "MogeLib.h"
#include "set"

namespace Moge
{
    class IKeyboardObserver;
    class IKey;
	class IKeyboardObservable
	{
	public:
		IKeyboardObservable() = default;
		virtual ~IKeyboardObservable() = default;
		void notifyKeyboardObservers( IKey* data = nullptr );

		void MogeLib_API registerObserver( IKeyboardObserver* observer );
		void MogeLib_API unregisterObserver( IKeyboardObserver* observer );

	protected:
	private:
        std::set<IKeyboardObserver*> observers;
	};
}