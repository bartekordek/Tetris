#include "ITimer.h"
#include "TimerChrono.h"
#include <SDL_timer.h>
using namespace Moge;

ITimer::ITimer()
{
}

ITimer::~ITimer()
{
}

void ITimer::SleepSeconds( const unsigned int seconds )
{
    SleepMiliSeconds( 1000 * seconds );
}

void ITimer::SleepMiliSeconds( const unsigned int mSeconds )
{
    SDL_Delay( mSeconds );
}

ITimer* TimerFactory::getChronoTimer()
{
    return new TimerChrono();
}