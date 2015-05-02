#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

int main( void )
{
	Fl_Window window( 300, 300, "OKNO" );
	Fl_Box box( 0, 0 , 300, 300, "haj wrld" );
	window.show();
	Fl::run();
	return 0;
}