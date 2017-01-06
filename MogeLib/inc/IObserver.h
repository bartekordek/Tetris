#pragma once

#include "IObservableData.h"

namespace Moge
{
	class MogeLib_API IObserver
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