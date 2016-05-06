#pragma once

#include "FileSystem.h"
#include "Node.h"
#include "SurfaceWrapper.h"

namespace MOGE
{
	using ImageSurface = std::shared_ptr<SurfaceWrapper>;

	class MOGE_API ImageCreator
	{
	public:
		static ImageSurface CreateSurfaceFromImage( const Path& imagePath );

	private:
		enum ImageTypes
		{
			UNKOWN = -1,
			BMP = 1,
			PNG,
			JPG
		};

		static ImageTypes GetImageType( const Path& imagePath );
	};
	
//
//	class NodeImageFactory
//	{
//	public:
//		static std::shared_ptr<SDL_Surface> CreateImage( const Path& imagePath );
//		static std::shared_ptr<SDL_Surface> CreateScreen( const Size& size, CUInt bitsPerPixel = 32 );
//		static std::shared_ptr<SDL_Surface> CreateImage( SDL_Surface* surface );
//	private:
//		static SDL_Surface* CreateSurface( const Path& imagePath );
////		static const IMAGETYPE GuessImageType( const Path& imagePath );
//	};
//
//	ImagePtr CreateSharedImgPtr( SDL_Surface* image );
}