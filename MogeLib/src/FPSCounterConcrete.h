#pragma once
#include "IFPSCounter.h"
#include <memory>
#include <atomic>
#include <thread>

namespace Moge
{
	class ITimer;
	class FPSCounterConcrete: public IFPSCounter
	{
	public:
		FPSCounterConcrete();
		virtual ~FPSCounterConcrete();

		void start() override;
		void increase() override;
		const unsigned int getFps()const override;
		
	protected:
	private:
		void counterLoop();

		std::thread mainThread;
		std::unique_ptr<ITimer> timer;
		std::atomic<bool> run = true;
		std::atomic<short> framesCount = 0;
		std::atomic<short> lastFrameValue = 0;
	};
}
