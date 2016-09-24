#include "NodeImageCreator.h"

#include <SDL.h>

namespace Moge
{
	ImageSurface ImageCreator::CreateSurfaceFromImage( const Path& imagePath )
	{
		SurfaceWrapper* surfaceWrapper = new SurfaceWrapper( imagePath );
		ImageTypes imageType = GetImageType( imagePath );
		if( ImageTypes::BMP == imageType )
		{
			surfaceWrapper->setNewSurface( SDL_LoadBMP( imagePath.c_str() ) );
		}
		ImageSurface surface;
		surface.reset( surfaceWrapper );
		return surface;
	}

	ImageCreator::ImageTypes ImageCreator::GetImageType( const Path& imagePath )
	{
		if( false == imagePath.empty() )
		{
			if( "bmp" == imagePath.Extension().ToLower() )
			{
				return ImageTypes::BMP;
			}
			else if( "png" == imagePath.Extension().ToLower() )
			{
				return ImageTypes::PNG;
			}
			else if( "jpg" == imagePath.Extension().ToLower() )
			{
				return ImageTypes::JPG;
			}
		}
		return ImageTypes::UNKOWN;
	}
}