#ifndef __SDL__WRAP__
#define __SDL__WRAP__

#include "Utils.h"
#include "MainGrid.h"
#include "SDL/SDL.h"

class CSDLWrapper
{
public:
	CSDLWrapper();
	virtual ~CSDLWrapper();

	void CreateWindow( CUInt width = 0, CUInt height = 0 );
	void AddImage( const String& path );

	void ApplyImage( CUInt imgIndex, CUInt x, CUInt y );
	void Display( const CMainGrid& grid );
	void Actualize();
	void MainLoop();

private:
	void m_ShowImages();
	const bool m_ImageExistOnList( const String& path )const;

	UInt m_width;
	UInt m_height;
	SDL_Surface* screen;
	std::vector<std::pair<SDL_Surface*, String>> images;
};

#endif 
