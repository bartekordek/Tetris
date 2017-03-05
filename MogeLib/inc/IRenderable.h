#pragma once

#include "MogeLib.h"
#include "Math/IPosition.h"
#include "ITexture.h"

namespace Moge
{
	class MogeLib_API IRenderable
	{
	public:
		IRenderable();
		virtual ~IRenderable();
		virtual const Math::IPosition<double>& getPosition()const = 0;
		virtual const ITexture* getTexture()const = 0;
	protected:
	private:
	};
}
