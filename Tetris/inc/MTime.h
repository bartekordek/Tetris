#ifndef _TIMER_C__
#define _TIMER_C__

#include "Utils.h"

/*
 * @brief Class for time management. 
 */
class CTimeMod
{
public:
	/*
	 * @brief Basic sleep function (seconds). 
	 * @param[in] const unsigned int number of seconds to sleep. 
	 */
	static void SleepSeconds( CUInt seconds );
	/*
	 * @brief Basic sleep function (miliseconds). 
	 * @param[in] const unsigned int number of miliseconds to sleep. 
	 */
	static void SleepMiliSeconds( CUInt mSeconds );
private:
};

#endif
