#ifndef __FLTK_WRPR__
#define __FLTK_WRPR__

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "MainGrid.h"
#include "Brick.h"
#include "Point.h"
#include "Utils.h"
#include "Game.h"
#include <string>

class FLTKWrapper
{
public:
	static FLTKWrapper* Instance();
	void InitWindow( const unsigned int xSize = 800, const unsigned ySize = 600 );
	void StartEventHandler();
	void Display( const CMainGrid& grid );
	void Display( Fl_RGB_Image* image, const CoordinatestList& coordinates );
	void DisplayImage( Fl_RGB_Image* image,
					   const CTableCoor& where = CTableCoor( 0, 0 ),
					   const unsigned width = 10, 
					   const unsigned height = 10);
	void Display( const CBrick& bricks );
	void SetWinColor();
	virtual ~FLTKWrapper();

private:
	FLTKWrapper();
	FLTKWrapper& operator=( const FLTKWrapper& wrapper );
	FLTKWrapper( const FLTKWrapper& wrapper );

	Fl_Button* m_CreateNewButton( 
		const unsigned int xPos, 
		const unsigned yPos, 
		const std::string& buttonText, 
		const unsigned width = 100, 
		const unsigned height = 50 );
	static void m_StartButtonCallBack( Fl_Widget*, void* );

	static FLTKWrapper* s_instance;

	Fl_Window* m_window;
	std::vector<Fl_Box*> m_boxArray;
	Fl_Button* m_startButton;

};


#endif