#pragma once
#include "ITimer.h"
#include "ITime.h"
#include <chrono>
#include <memory>
namespace Moge
{
	class TimerChrono: public ITimer
	{
	public:
		TimerChrono( const bool run = false );
		virtual ~TimerChrono();

		void start() override;
		void stop() override;
		void reset() override;
		const ITime& getElapsed()const override;

	protected:
	private:
		std::chrono::high_resolution_clock clock;
		std::chrono::high_resolution_clock::time_point startPoint;
		std::unique_ptr<ITime> time;
	};
}