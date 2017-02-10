#include "MTime.h"
#include <SDL.h>

namespace Moge
{
	void CTimeMod::SleepSeconds( const unsigned int seconds )
	{
		SleepMiliSeconds( 1000 * seconds );
	}

	void CTimeMod::SleepMiliSeconds( const unsigned int mSeconds )
	{
		SDL_Delay( mSeconds );
	}
}