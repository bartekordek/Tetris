#pragma once

#include "MogeLib.h"

namespace Moge
{
	class MogeLib_API ITexture
	{
	public:
		ITexture();
		virtual ~ITexture();
		virtual const char* getPath()const = 0;
	protected:
	private:
	};
}