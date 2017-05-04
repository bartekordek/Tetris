#include "FPSCounterConcrete.h"
#include "ITimer.h"
using namespace Moge;


FPSCounterConcrete::FPSCounterConcrete()
{
	this->timer.reset( TimerFactory::getChronoTimer() );
	start();
}

FPSCounterConcrete::~FPSCounterConcrete()
{
	this->run = false;
	this->mainThread.join();
}

void FPSCounterConcrete::start()
{
	this->mainThread = std::thread( &FPSCounterConcrete::counterLoop, this );
}

void FPSCounterConcrete::increase()
{
	++this->framesCount;
}

const unsigned FPSCounterConcrete::getFps() const
{
	return this->lastFrameValue;
}

void FPSCounterConcrete::counterLoop()
{
	while( this->run )
	{
		ITimer::SleepSeconds( 1 );
		this->lastFrameValue.store( this->framesCount );
		this->framesCount = 0;
	}
}
