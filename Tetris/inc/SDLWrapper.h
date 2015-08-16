#ifndef __SDL__WRAP__
#define __SDL__WRAP__

#include "Utils.h"
#include "MainGrid.h"
#include "Button.h"
#include "SDL/SDL.h"

class CSDLWrapper
{
public:
	static CSDLWrapper* Instance();
	static void Destroy();

	void CreateWindow( CUInt width = 0, CUInt height = 0 );
	void AddImage( const String& path );

	void ApplyImage( CUInt imgIndex, CUInt x, CUInt y );
	void Display( const CMainGrid& grid );
	void Display( const CButton& button );
	void Actualize();
	void MainLoop();

private:
	CSDLWrapper();
	virtual ~CSDLWrapper();
	static CSDLWrapper* s_instance;
	void m_ShowImages();
	const bool m_ImageExistOnList( const String& path )const;

	UInt m_width;
	UInt m_height;
	SDL_Surface* screen;
	std::vector<std::pair<SDL_Surface*, String>> images;
};

#endif 
