#pragma once

#include "Node.h"

namespace MOGE
{
	using ImagePtr = SharedPtr<SDL_Surface>;

	class NodeImageFactory
	{
	public:
		static ImagePtr CreateImage( const Path& imagePath );
		static ImagePtr CreateScreen( const Size& size, CUInt bitsPerPixel = 32 );
	private:
		static SDL_Surface* CreateSurface( const Path& imagePath );
		static const IMAGETYPE GuessImageType( const Path& imagePath );
	};

	ImagePtr CreateSharedImgPtr( SDL_Surface* image );
}