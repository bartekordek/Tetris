#pragma once
namespace Moge
{
    class FrameData final
    {
    public:
        FrameData( void );
        ~FrameData( void );

        void setTargetFpsCount( const double fps );
        void setLastFrimeTimeUs( const double lastFrimeTimeUs );
        void setLastFpsCount( const double fpsCount );
        const double getTargetFpsCount()const;
        const double getSleepTimeUs()const;

    protected:
    private:
        double m_us = 1.0 / ( 1000 * 1000 );
        double m_frameTimeLastUs = ( 1000 * 1000 ) / 60.0;
        double m_frameTimeTargetUs = ( 1000 * 1000 ) / 60.0;

        double m_fpsCountTarget = 0.0;
        double m_fpsCountCurrent = 60.0;
        double m_fpsEpislon = 0.0001;
        
        double m_calculationsTimeMs = 0.0;
        double m_sleepTimeDeltaUs = 2.0;
        double m_sleepTimeUs = m_frameTimeTargetUs * 0.8;
    };
}