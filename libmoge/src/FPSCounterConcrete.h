#pragma once
#include "IFPSCounter.h"

#include "CUL/ITimer.hpp"

#include <memory>
#include <atomic>
#include <thread>

#include <boost/circular_buffer.hpp>

namespace Moge
{
    class FPSCounterConcrete: public IFPSCounter
    {
    public:
        FPSCounterConcrete();
        virtual ~FPSCounterConcrete();

        void start() override;
        void increase() override;
        const double getCurrentFps()const override;
        const double getAverageFps()const override;
        
    protected:
    private:
        void counterLoop();
        const double calculateAverageFps()const;
        unsigned int bufferSize = 4;

        std::thread mainThread;
        std::unique_ptr<CUL::ITimer> timer;
        std::atomic<bool> run = { true };
        std::atomic<unsigned> framesCount = { 0 };
        std::atomic<unsigned> lastFrameValue = { 0 };
        boost::circular_buffer<unsigned> samples;
        unsigned int sampleSize = 10;
        std::atomic<double> averageFps = { 0.0 };
    };
}
