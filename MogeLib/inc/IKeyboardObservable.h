#pragma once

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

        void registerObserver( IKeyboardObserver* observer );
        void unregisterObserver( IKeyboardObserver* observer );

	protected:
	private:
        std::set<IKeyboardObserver*> observers;
	};
}