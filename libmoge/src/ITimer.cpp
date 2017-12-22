#include "ITimer.h"
#include "TimerChrono.h"

using namespace Moge;

ITimer::ITimer()
{
}

ITimer::~ITimer()
{
}

ITimer* TimerFactory::getChronoTimer()
{
    return new TimerChrono();
}