#include "NodeImageFactory.h"

namespace MOGE
{
	ImagePtr NodeImageFactory::CreateImage( const Path& imagePath )
	{
		SDL_Surface* image = CreateSurface( imagePath );
		ImagePtr imagePtr = CreateSharedImgPtr( image );
		return imagePtr;
	}

	ImagePtr NodeImageFactory::CreateScreen( const Size& size, CUInt bitsPerPixel )
	{
		SDL_Surface* image = SDL_SetVideoMode( 
			size.GetWidth(), 
			size.GetHeight(), 
			bitsPerPixel, 
			SDL_HWSURFACE );
		ImagePtr imagePtr = CreateSharedImgPtr( image );
		return imagePtr;
	}

	ImagePtr NodeImageFactory::CreateImage( SDL_Surface* surface )
	{
		return  CreateSharedImgPtr( surface );
	}

	SDL_Surface* NodeImageFactory::CreateSurface( const Path& imagePath )
	{
		SDL_Surface* image = nullptr;
		IMAGETYPE imageType = GuessImageType( imagePath );
		if( IMAGETYPE::BMP == imageType )
		{
			image = SDL_LoadBMP( imagePath.c_str() );
		}
		else if( IMAGETYPE::PNG == imageType )
		{
		}
			
		return image;
	}

	const IMAGETYPE NodeImageFactory::GuessImageType( const Path& imagePath )
	{
		IMAGETYPE imageType = IMAGETYPE::UNKOWN;
		if( false == imagePath.empty() )
		{
			const String extension = imagePath.extension();
			if( extension.find( "bmp" ) != std::string::npos )
			{
				return IMAGETYPE::BMP;
			}
			else if( extension.find( "png" ) != std::string::npos )
			{
				return IMAGETYPE::PNG;
			}
		}
		return imageType;
	}

	ImagePtr CreateSharedImgPtr( SDL_Surface* image )
	{
		return std::make_shared<SDL_Surface>( *image );
	}
}