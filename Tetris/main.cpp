#include "Game.h"

#include <ConsoleUtilities.h>

int main( int argc, char *argv[] )
{
	MogeLib::ConsoleUtilities::PrintInputParameters( argc, argv );
	Tetris::CGame game;
	game.Initialize( 22, 10 );
	game.ShowGrid();
	game.StartGame();
	game.MainLoop();
	return 0;
}
