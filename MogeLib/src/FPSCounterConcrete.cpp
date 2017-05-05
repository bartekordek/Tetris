#include "FPSCounterConcrete.h"
#include "ITimer.h"
using namespace Moge;

FPSCounterConcrete::FPSCounterConcrete()
{
	this->samples.set_capacity( this->bufferSize );
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

const unsigned FPSCounterConcrete::getCurrentFps() const
{
	return this->lastFrameValue;
}

const unsigned FPSCounterConcrete::getAverageFps() const
{
	return this->averageFps;
}

void FPSCounterConcrete::setAverageFpsSample( const unsigned sampleSize )
{
	this->sampleSize = sampleSize;
}

void FPSCounterConcrete::counterLoop()
{
	while( this->run )
	{
		ITimer::SleepSeconds( 1 );
		this->lastFrameValue.store( this->framesCount );
		this->samples.push_front( this->lastFrameValue );
		this->averageFps = calculateAverageFps();
		this->framesCount = 0;
	}
}

const unsigned int FPSCounterConcrete::calculateAverageFps()const
{
	if( 0 == this->samples.size() )
	{
		return 0;
	}
	unsigned int sampleSizeRealVal = static_cast<unsigned int>( this->samples.size() );
	unsigned int sampleSizeReal = this->sampleSize < sampleSizeRealVal ? this->sampleSize : sampleSizeRealVal;
	short sum = 0;
	for( unsigned int i = 0; i < sampleSizeReal; ++i )
	{
		sum += this->samples[i];
	}
	return static_cast<unsigned int>( sum ) / sampleSizeReal;
}