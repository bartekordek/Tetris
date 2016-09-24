#pragma once

#include "MogeLib.h"
#include "Aliases.h"

namespace Moge
{
	class MogeLib_API CTimeMod
	{
	public:
		static void SleepSeconds( CUInt seconds );
		static void SleepMiliSeconds( CUInt mSeconds );
	private:
	};
}