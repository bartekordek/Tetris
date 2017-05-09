#pragma once
#include "IFPSCounter.h"
#include <memory>
#include <atomic>
#include <thread>
#include <boost/circular_buffer.hpp>

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
		const unsigned int getCurrentFps()const override;
		const unsigned int getAverageFps()const override;
		void setAverageFpsSample( const unsigned int sampleSize ) override;
		
	protected:
	private:
		void counterLoop();
		const unsigned int calculateAverageFps()const;
		unsigned int bufferSize = 100;

		std::thread mainThread;
		std::unique_ptr<ITimer> timer;
		std::atomic<bool> run = { true };
		std::atomic<short> framesCount = { 0 };
		std::atomic<short> lastFrameValue = { 0 };
		boost::circular_buffer<short> samples;
		unsigned int sampleSize = 10;
		std::atomic<short> averageFps = { 0 };
	};
}
