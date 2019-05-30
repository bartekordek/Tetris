#include "FramesData.hpp"

#include <iostream>

using namespace Moge;

FrameData::FrameData( void )
{
    setTargetFpsCount( 60.0 );
}

FrameData::~FrameData( void )
{
}

void FrameData::setTargetFpsCount( const double fps )
{
    this->m_fpsCountTarget = fps;
    this->m_frameTimeTargetUs = 1.0 / ( fps * 1000.0 * 1000.0 );
}

void FrameData::setLastFpsCount( const double fpsCount )
{
    if( abs( fpsCount - this->m_fpsCountTarget ) > m_fpsEpislon )
    {
        if( fpsCount > this->m_fpsCountTarget )
        {
            this->m_sleepTimeUs += m_sleepTimeDeltaUs;
        }
        else if( fpsCount < this->m_fpsCountTarget )
        {
            this->m_sleepTimeUs -= m_sleepTimeDeltaUs;
        }
        this->m_fpsCountCurrent = fpsCount;
    }
}

void FrameData::setLastFrimeTimeUs( const double lastFrimeTimeUs )
{
    if( lastFrimeTimeUs > m_frameTimeTargetUs )
    {
        this->m_sleepTimeUs -= m_sleepTimeDeltaUs;
    }
    else if( lastFrimeTimeUs < m_frameTimeTargetUs )
    {
        this->m_sleepTimeUs += m_sleepTimeDeltaUs;
    }
    this->m_frameTimeLastUs = lastFrimeTimeUs;
}

const double FrameData::getTargetFpsCount()const
{
    return this->m_fpsCountTarget;
}

const double FrameData::getSleepTimeUs()const
{
    return this->m_sleepTimeUs;
}