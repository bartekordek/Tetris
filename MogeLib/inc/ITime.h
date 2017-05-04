#pragma once
#include "MogeLib.h"
namespace Moge
{
	class MogeLib_API ITime
	{
	public:
		ITime() = default;
		virtual ~ITime() = default;

		virtual void setTimeMs( const unsigned int time ) = 0;
		virtual const unsigned int getMs()const = 0;
		virtual const unsigned int getS()const = 0;
		virtual const unsigned int getM()const = 0;
		virtual const unsigned int getH()const = 0;
	};
}