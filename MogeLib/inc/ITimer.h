#pragma once
#include "ITime.h"
namespace Moge 
{
    class MogeLib_API ITimer
    {
    public:
        ITimer();
        virtual ~ITimer();

        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void reset() = 0;
        virtual const ITime& getElapsed()const = 0;

        virtual void sleepSeconds( const unsigned int seconds )const = 0;
        virtual void sleepMiliSeconds( const unsigned int mSeconds )const = 0;
        virtual void sleepMicroSeconds( const unsigned int uSeconds )const = 0;

    };

    class MogeLib_API TimerFactory
    {
    public:
        static ITimer* getChronoTimer();
    private:
    };
}