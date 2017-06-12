#pragma once
#include "MogeLib.h"
namespace Moge
{
	class MogeLib_API IEventLoop
	{
	public:
		IEventLoop() = default;
		virtual ~IEventLoop() = default;
		virtual void runEventLoop() = 0;
		virtual void stopEventLoop() = 0;

	protected:
	private:
	};
}