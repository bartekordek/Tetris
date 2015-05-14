#ifndef __FLTK_WRPR__
#define __FLTK_WRPR__

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_BMP_Image.H>
#include "MainGrid.h"
#include <string>

class FLTKWrapper
{
public:
	static FLTKWrapper* Instance();
	void InitWindow( const unsigned int xSize = 800, const unsigned ySize = 600 );
	void ShowWindow();
	void Display( const CMainGrid& grid );
	void DisplayImage( 
		Fl_BMP_Image* image,
		const unsigned int xPos, 
		const unsigned int yPos,
		const unsigned int width,
		const unsigned int height);

	virtual ~FLTKWrapper();

private:
	FLTKWrapper();
	FLTKWrapper& operator=( const FLTKWrapper& wrapper );
	FLTKWrapper( const FLTKWrapper& wrapper );
	static FLTKWrapper* s_instance;

	Fl_Window* m_window;
	std::vector<Fl_Box*> m_boxArray;

};


#endif