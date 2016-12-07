#pragma once

#include "IObserver.h"
#include <set>
#include <mutex>

namespace Moge
{
	class IObservable
	{
	public:
		IObservable()
		{
		}

		virtual ~IObservable()
		{
		}

		void registerObserver( IObserver* observer )
		{
			std::lock_guard<std::mutex> lck( this->observersMutex );
			this->observers.insert( observer );
		}

		void unregisterObserver( IObserver* observer )
		{
			std::lock_guard<std::mutex> lck( this->observersMutex );
			this->observers.erase( observer );
		}

		void notify( IObservableData* data )
		{
			std::lock_guard<std::mutex> lck( this->observersMutex );
			for( const auto& observer: this->observers )
			{
				observer->update( data );
			}
		}

	protected:
	private:
		std::set<IObserver*> observers;
		std::mutex observersMutex;
	};
}