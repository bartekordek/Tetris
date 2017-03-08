#pragma once
#include "ITexture.h"
namespace Moge
{
	class TextureSDL: public ITexture
	{
	public:
		TextureSDL();
		TextureSDL(const TextureSDL& orig);
		virtual ~TextureSDL();
	private:
		SupportedRenderers renderer = SupportedRenderers::R_SDL;
	};
}