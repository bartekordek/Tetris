#include "Game.h"

#include <ConsoleUtilities.h>

int main( int argc, char *argv[] )
{
	Moge::ConsoleUtilities::PrintInputParameters( argc, argv );
	Tetris::CGame game;
	game.initialize( 22, 10 );
	game.run();
	return 0;
}
