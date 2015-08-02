#include "MTime.h"
#ifdef _WIN32
	#include "SDL\SDL.h"
#else
	#include "SDL/SDL.h"
#endif


void CTimeMod::SleepMiliSeconds( CUInt mSeconds )
{
	SDL_Delay( mSeconds );
}

void CTimeMod::SleepSeconds( CUInt seconds )
{
	SleepMiliSeconds( 1000 * seconds );
}
