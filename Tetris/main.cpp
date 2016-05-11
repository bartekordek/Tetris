#include "inc/Game.h"
#include <boost/log/core.hpp>

#include <ConsoleUtilities.h>

int main( int argc, char *argv[] )
{
	MOGE::ConsoleUtilities::PrintInputParameters( argc, argv );
	const unsigned int columnsCount = 10;
	const unsigned int rowsCount = 22;
	Tetris::CGame game;
	game.Initialize( rowsCount, columnsCount );
	game.ShowGrid();
	game.StartGame();
	game.MainLoop();

	boost::log::core::get()->remove_all_sinks();
	return 0;
}
