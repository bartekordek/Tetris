#pragma once

#include "Utilities.h"
#include "MainGrid.h"
#include "SDL.h"

class CSDLWrapper
{
public:
	CSDLWrapper();
	virtual ~CSDLWrapper();

	void CreateWindow( CUInt width = 0, CUInt height = 0 );
	void AddImage( const Path& path );

	void ApplyImage( CUInt imgIndex, CUInt x, CUInt y );
	void Display( const CMainGrid& grid );
	void Actualize();
	void MainLoop();

private:
	void m_ShowImages();
	const bool m_ImageExistOnList( const Path& path )const;

	UInt m_width;
	UInt m_height;
	SDL_Surface* screen;
	Vector<Pair<SDL_Surface*, std::string>> images;
};