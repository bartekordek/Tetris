#pragma once
#include "MogeLib.h"
namespace Moge
{
	class IRenderable;
	class MogeLib_API IRenderer
	{
	public:
		IRenderer();
		virtual ~IRenderer();
		virtual void forceDestroy() = 0;
		virtual void render( IRenderable* renderable ) = 0;
	protected:
	private:
	};
}