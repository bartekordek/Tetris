#pragma once

#include "IObservableData.h"

namespace Moge
{
	class IObserver
	{
	public:
		IObserver()
		{
		}

		virtual ~IObserver()
		{
		}

		virtual void update( IObservableData* data ) = 0;
	protected:
	private:
	};
}