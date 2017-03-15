#pragma once

#include "IRenderer.h"

namespace Moge
{
	class SDLRenderer: public IRenderer
	{
	public:
		SDLRenderer();
		virtual ~SDLRenderer();
				virtual void forceDestroy() = 0;
		virtual void render( IRenderable* renderable ) = 0;
		virtual SDL_Renderer* getSdlRenderer() = 0;
	protected:
	private:
	};
}