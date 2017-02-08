#pragma once

#include <set>

namespace Moge
{
	class IObserver;
	class IObservableData;
	class IObservable
	{
	public:
		IObservable() = default;
		virtual ~IObservable() = default;
		void registerObserver( IObserver* observer );
		void unregisterObserver( IObserver* observer );
		virtual void notifyKeyboardObservers( IObservableData* data = nullptr ) = 0;
	protected:
		std::set<IObserver*> observers;
	private:
		
	};
}