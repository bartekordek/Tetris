#include "NodeImageCreator.h"

#include <SDL.h>

namespace Moge
{
	ImageSurface ImageCreator::CreateSurfaceFromImage( const Path& imagePath )
	{
		ImageSurface result;
		SurfaceWrapper* surfaceWrapper = new SurfaceWrapper();
		ImageTypes imageType = GetImageType( imagePath );
		if( ImageTypes::BMP == imageType )
		{
			*surfaceWrapper = SDL_LoadBMP( imagePath.c_str() );
			result.reset(surfaceWrapper);
		}
		return result;
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