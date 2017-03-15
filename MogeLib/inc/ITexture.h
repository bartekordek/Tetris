#pragma once

#include "MogeLib.h"
#include "SupportedRenderersList.h"

struct SDL_Renderer;
namespace Moge
{
	class MogeLib_API ITexture
	{
	public:
		ITexture();
		virtual ~ITexture();
		virtual const char* getPath()const = 0;
		virtual const SupportedRenderers getRendererId()const = 0;
		SDL_Renderer* getSDLrenderer();
	protected:
	private:
	};
}