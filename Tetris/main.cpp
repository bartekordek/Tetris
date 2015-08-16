#include "inc/Game.h"

int main( int argc, char *argv[] )
{
	const unsigned int columnsCount = 10;
	const unsigned int rowsCount = 22;
	CGame game;
	game.Initialize( rowsCount, columnsCount );
	game.InitWindow();
	game.ShowGrid();
	game.StartGame();
	game.MainLoop();
	return 0;
}
