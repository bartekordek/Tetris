#ifndef __FLTK_WRPR__
#define __FLTK_WRPR__

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Button.H>
#include "MainGrid.h"
#include "Brick.h"
#include "Point.h"
#include <string>

class FLTKWrapper
{
public:
	static FLTKWrapper* Instance();
	void InitWindow( const unsigned int xSize = 800, const unsigned ySize = 600 );
	void ShowWindow();
	void Display( const CMainGrid& grid );
	void DisplayImage( Fl_RGB_Image* image,
					   const CPoint& where = CPoint( 0,0 ), 
					   const unsigned width = 10, 
					   const unsigned height = 10);
	void Display( const CBrick& bricks );
	virtual ~FLTKWrapper();

private:
	FLTKWrapper();
	FLTKWrapper& operator=( const FLTKWrapper& wrapper );
	FLTKWrapper( const FLTKWrapper& wrapper );

	Fl_Button* m_CreateNewButton( 
		const unsigned int xPos, 
		const unsigned yPos, 
		const std::string& buttonText, 
		const unsigned width = 50, 
		const unsigned height = 20 );

	static FLTKWrapper* s_instance;

	Fl_Window* m_window;
	std::vector<Fl_Box*> m_boxArray;
	Fl_Button* m_startButton;

};


#endif