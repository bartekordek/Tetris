#include "SurfaceFactory.h"
#include "MogeLibMain.h"

#include <SDL.h>
#include <boost/assert.hpp>

namespace Moge
{
	ImageSurface SurfaceFactory::CreateSurfaceFromImage( const Path& imagePath )
	{
		SurfaceWrapper* surfaceWrapper = new SurfaceWrapper( imagePath );
		ImageTypes imageType = GetImageType( imagePath );
		if( ImageTypes::BMP == imageType )
		{
			surfaceWrapper->setNewSurface( SDL_LoadBMP( imagePath.c_str() ) );
			BOOST_ASSERT( surfaceWrapper->GetSdlSurface() != nullptr  );
		}
		ImageSurface surface;
		surface.reset( surfaceWrapper );
		return surface;
	}

	SurfaceFactory::ImageTypes SurfaceFactory::GetImageType( const Path& imagePath )
	{
		if( false == imagePath.empty() )
		{
			if( ".bmp" == imagePath.Extension().ToLower() )
			{
				return ImageTypes::BMP;
			}
			if( ".png" == imagePath.Extension().ToLower() )
			{
				return ImageTypes::PNG;
			}
			if( ".jpg" == imagePath.Extension().ToLower() )
			{
				return ImageTypes::JPG;
			}
		}
		return ImageTypes::UNKOWN;
	}
}
