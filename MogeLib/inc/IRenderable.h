#pragma once

#include "MogeLib.h"
#include "RenderableTypes.h"
#include "Math/IPosition.h"
#include "Math/ISize.h"

namespace Moge
{
	class MogeLib_API IRenderable
	{
	public:
		IRenderable();
		virtual ~IRenderable();
		virtual Math::IPosition<double>* getPosition() = 0;
		virtual const Math::IPosition<double>* getPosition()const = 0;
		virtual Math::ISize<double>* getSize() = 0;
		virtual const Math::ISize<double>* getSize()const = 0;
		virtual const RenderableType getRenderableType()const = 0;
	protected:
	private://TODO Write texture render method.
		
	};
}
