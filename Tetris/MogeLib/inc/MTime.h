#pragma once

#include "MOGE.h"
#include "Aliases.h"

namespace MogeLib
{
	class MOGE_API CTimeMod
	{
	public:
		static void SleepSeconds( CUInt seconds );
		static void SleepMiliSeconds( CUInt mSeconds );
	private:
	};
}