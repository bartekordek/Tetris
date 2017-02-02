#pragma once

#include "MogeLib.h"

namespace Moge
{
	class IObservableData;
	class MogeLib_API IObserver
	{
	public:
		IObserver() = default;
		virtual ~IObserver() = default;
	protected:
	private:
	};
}