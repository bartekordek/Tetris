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

        static void SleepSeconds( const unsigned int seconds );
        static void SleepMiliSeconds( const unsigned int mSeconds );

    };

    class MogeLib_API TimerFactory
    {
    public:
        static ITimer* getChronoTimer();
    private:
    };
}