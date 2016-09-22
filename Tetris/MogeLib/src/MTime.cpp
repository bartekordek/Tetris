#include "MTime.h"
#include <SDL.h>

namespace Moge
{
	void CTimeMod::SleepSeconds( CUInt seconds )
	{
		SleepMiliSeconds( 1000 * seconds );
	}

	void CTimeMod::SleepMiliSeconds( CUInt mSeconds )
	{
		SDL_Delay( mSeconds );
	}
}