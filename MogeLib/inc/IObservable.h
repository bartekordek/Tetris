#pragma once

#include "MogeLib.h"

namespace Moge
{
	class IObservableImpl;
	class IObserver;
	class IObservableData;
	class MogeLib_API IObservable
	{
	public:
		IObservable();
		virtual ~IObservable();

		void registerObserver( IObserver* observer );
		//{
		//	std::lock_guard<std::mutex> lck( this->observersMutex );
		//	this->observers.insert( observer );
		//}

		void unregisterObserver( IObserver* observer )
		{
	/*		std::lock_guard<std::mutex> lck( this->observersMutex );
			this->observers.erase( observer );*/
		}

		void notify( IObservableData* data )
		{
			//std::lock_guard<std::mutex> lck( this->observersMutex );
			//for( const auto& observer: this->observers )
			//{
			//	observer->update( data );
			//}
		}

	protected:
	private:
		IObservableImpl* impl = nullptr;
	};
}