#include "TimerChrono.h"
#include "TimeConcrete.h"
#include <chrono>
#include <thread>
#include <memory>
using namespace Moge;

TimerChrono::TimerChrono( const bool run )
{
    this->time.reset( new TimeConcrete() );
    if( run )
    {
        this->reset();
    }
}

TimerChrono::~TimerChrono()
{
    
}

void TimerChrono::start()
{
    this->reset();
}

void TimerChrono::stop()
{
    
}

void TimerChrono::reset()
{
    this->startPoint = this->clock.now();
}

const ITime& TimerChrono::getElapsed() const
{
    auto difference = this->clock.now() - startPoint;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>( difference ).count();
    auto msUInt = static_cast<unsigned int>( ms );
    this->time->setTimeMs( msUInt );
    return *this->time;
}

void TimerChrono::sleepSeconds( const unsigned int seconds )const
{
    std::this_thread::sleep_for( std::chrono::seconds( seconds ) );
}

void TimerChrono::sleepMiliSeconds( const unsigned int mSeconds )const
{
    std::this_thread::sleep_for( std::chrono::milliseconds( mSeconds ) );
}

void TimerChrono::sleepMicroSeconds( const unsigned int uSeconds )const
{
    std::this_thread::sleep_for( std::chrono::microseconds( uSeconds ) );
}