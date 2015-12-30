#include "SDLWrapper.h"

CSDLWrapper::~CSDLWrapper()
{
	for( auto it = images.begin(); it != images.end(); ++it )
	{
		SDL_FreeSurface( it->first );
	}
	SDL_Quit();
}

void CSDLWrapper::CreateWindow( CUInt width, CUInt height )
{
	m_width = width;
	m_height = height;

	SDL_Init( SDL_INIT_EVERYTHING );
	screen = SDL_SetVideoMode( width, height, 32, SDL_HWSURFACE );
} 

void CSDLWrapper::AddImage( const String& path )
{
	if( false == m_ImageExistOnList( path ) )
	{
		SDL_Surface* surface = SDL_LoadBMP( path.c_str() );
		std::pair<SDL_Surface*, String> image( surface, path );
		images.push_back( image );
	}	
}

const bool CSDLWrapper::m_ImageExistOnList( const String& path )const
{
	for( auto it = images.begin(); it != images.end(); ++it )
	{
		if( path == it->second )
		{
			return true;
		}
	}
	return false;
}

void CSDLWrapper::Display( const CMainGrid& grid )
{
	for( UInt i = 0; i < grid.SlabCount(); ++i )
	{
		if( true == grid.PartOfSlab( i ) )
		{
			ApplyImage( 1, grid.GetSlabCol( i ) * 10, grid.GetSlabRow( i ) * 10 );
		}
		else
		{
			ApplyImage( 0, grid.GetSlabCol( i ) * 10, grid.GetSlabRow( i ) * 10 );
		}
	}
	Actualize();
}


void CSDLWrapper::ApplyImage( CUInt imgIndex, CUInt x, CUInt y )
{
	SDL_Rect offset;
	offset.x = static_cast<Sint16>( x );
	offset.y = static_cast<Sint16>( y );
	offset.h = 10;
	offset.w = 10;
	SDL_BlitSurface( images[imgIndex].first, NULL, screen, &offset );
}

void CSDLWrapper::Actualize()
{
	SDL_Flip( screen );
}

CSDLWrapper::CSDLWrapper(): m_width(0), m_height(0), screen(NULL)
{
}

void CSDLWrapper::MainLoop()
{

}