#include "inc/Game.h"

#include <ConsoleUtilities.h>

int main( int argc, char *argv[] )
{
	MogeLib::ConsoleUtilities::PrintInputParameters( argc, argv );
	const unsigned int columnsCount = 10;
	const unsigned int rowsCount = 22;
	Tetris::CGame game;
	game.Initialize( rowsCount, columnsCount );
	game.ShowGrid();
	game.StartGame();
	game.MainLoop();
	return 0;
}
