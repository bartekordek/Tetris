#include "NodeImageCreator.h"

#include <SDL.h>

namespace MOGE
{
	ImageSurface ImageCreator::CreateSurfaceFromImage( const Path& imagePath )
	{
		ImageSurface result;
		SurfaceWrapper* surfaceWrapper = new SurfaceWrapper();
		ImageTypes imageType = GetImageType( imagePath );
		BOOST_ASSERT( imagePath.Exist() );
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
	//ImagePtr NodeImageFactory::CreateImage( const Path& imagePath )
	//{
	//	SDL_Surface* image = CreateSurface( imagePath );
	//	ImagePtr imagePtr = CreateSharedImgPtr( image );
	//	return imagePtr;
	//}

	//ImagePtr NodeImageFactory::CreateScreen( const Size& size, CUInt bitsPerPixel )
	//{
	///*	SDL_Window* image = SDL_CreateWindow(
	//		"Tetris",
	//		0,
	//		0,
	//		size.GetWidth(), 
	//		size.GetHeight(), 
	//		SDL_WINDOW_OPENGL );
	//	ImagePtr imagePtr = CreateSharedImgPtr( image );
	//	return imagePtr;*/
	//	return ImagePtr();
	//}

	//ImagePtr NodeImageFactory::CreateImage( SDL_Surface* surface )
	//{
	//	return  CreateSharedImgPtr( surface );
	//}

	//SDL_Surface* NodeImageFactory::CreateSurface( const Path& imagePath )
	//{
	//	/*SDL_Surface* image = nullptr;
	//	IMAGETYPE imageType = GuessImageType( imagePath );
	//	if( IMAGETYPE::BMP == imageType )
	//	{
	//		image = SDL_LoadBMP( imagePath.c_str() );
	//	}
	//	else if( IMAGETYPE::PNG == imageType )
	//	{
	//	}
	//		
	//	return image;*/
	//	return nullptr;
	//}

	////const IMAGETYPE NodeImageFactory::GuessImageType( const Path& imagePath )
	////{
	////	IMAGETYPE imageType = IMAGETYPE::UNKOWN;
	////	if( false == imagePath.empty() )
	////	{
	////		const String extension = imagePath.extension();
	////		if( extension.find( "bmp" ) != std::string::npos )
	////		{
	////			return IMAGETYPE::BMP;
	////		}
	////		else if( extension.find( "png" ) != std::string::npos )
	////		{
	////			return IMAGETYPE::PNG;
	////		}
	////	}
	////	return imageType;
	////}

	//ImagePtr CreateSharedImgPtr( SDL_Surface* image )
	//{
	//	return std::make_shared<SDL_Surface>( *image );
	//}
}