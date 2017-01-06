#pragma once

#include "IObserver.h"

#include <set>
#include <mutex>

namespace Moge
{
	class IObservableImpl
	{
	public:
		IObservableImpl();
		virtual ~IObservableImpl();
	protected:
	private:

		std::set<IObserver*> observers;
		std::mutex observersMutex;
	};
}