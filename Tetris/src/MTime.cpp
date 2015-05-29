#include "MTime.h"
#include <chrono>
#include <thread>


void CTimeMod::SleepMiliSeconds( CUInt mSeconds )
{
	std::this_thread::sleep_for( std::chrono::milliseconds( mSeconds ) );
}

void CTimeMod::SleepSeconds( CUInt seconds )
{
	std::this_thread::sleep_for( std::chrono::seconds( seconds) );
}