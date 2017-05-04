#pragma once
#include "MogeLib.h"
namespace Moge
{
	class MogeLib_API IFPSCounter
	{
	public:
		IFPSCounter();
		virtual ~IFPSCounter();

		virtual void start() = 0;
		virtual void increase() = 0;
		virtual const unsigned int getFps()const = 0;
	};

	class FPSCounterFactory
	{
	public:
		static IFPSCounter* getConcreteFPSCounter();
	protected:
	private:
	};
}