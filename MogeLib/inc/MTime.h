#pragma once

#include "MogeLib.h"

namespace Moge
{
	class MogeLib_API CTimeMod
	{
	public:
		static void SleepSeconds( const unsigned int seconds );
		static void SleepMiliSeconds( const unsigned int mSeconds );
	private:
	};
}