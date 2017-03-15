#pragma once
#include "IRenderer.h"
namespace Moge
{
	class Renderer;
	class MogeLib_API IRenderer2D: public IRenderer
	{
	public:
		IRenderer2D() = default;
		virtual ~IRenderer2D() = default;
		virtual Renderer* getRenderer() = 0;
	protected:
	private:
	};
}