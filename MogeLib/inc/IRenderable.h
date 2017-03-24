#pragma once

#include "MogeLib.h"
#include "Math/IPosition.h"
#include "ITexture.h"
#include "Math/ISize.h"

namespace Moge
{
	class MogeLib_API IRenderable
	{
	public:
		IRenderable();
		virtual ~IRenderable();
		virtual const Math::IPosition<double>& getPosition()const = 0;
		virtual const Math::ISize<double>& getSize()const = 0;
		virtual void render() = 0;
	protected:
	private://TODO Write texture render method.
	};
}
