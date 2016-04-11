#include "MTime.h"
#include <SDL.h>


void CTimeMod::SleepMiliSeconds( CUInt mSeconds )
{
	SDL_Delay( mSeconds );
}

void CTimeMod::SleepSeconds( CUInt seconds )
{
	SleepMiliSeconds( 1000 * seconds );
}
