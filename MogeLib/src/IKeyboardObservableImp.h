#pragma once

#include <set>

namespace Moge 
{
	class IKeyboardObserver;
	class IKey;
	class IKeyboardObservableImp
	{
	public:
		IKeyboardObservableImp() = default;
		virtual ~IKeyboardObservableImp() = default;
		void notifyKeyboardObservers( IKey* data = nullptr );
		void registerObserver( IKeyboardObserver* observer );
		void unregisterObserver( IKeyboardObserver* observer );
	protected:
	private:
		std::set<IKeyboardObserver*> observers;
	};
}