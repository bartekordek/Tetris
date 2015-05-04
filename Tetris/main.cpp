#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

#include "Game.h"

int main( void )
{
	CGame::Instance()->Initialize();

	Fl_Window window( 300, 300, "OKNO" );
	Fl_Box box( 0, 0 , 300, 300, "haj wrld" );
	window.show();
	Fl::run();
	CGame::Instance()->Destroy();
	return 0;
}