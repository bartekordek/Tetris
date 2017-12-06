#include "IFPSCounter.h"
#include "FPSCounterConcrete.h"
using namespace Moge;

IFPSCounter::IFPSCounter()
{
}

IFPSCounter::~IFPSCounter()
{
}

IFPSCounter* FPSCounterFactory::getConcreteFPSCounter()
{
    return new FPSCounterConcrete();
}