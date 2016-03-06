#include "inc/Game.h"
#include <boost/log/core.hpp>

int main( int argc, char *argv[] )
{
	boost::filesystem::path::imbue( std::locale( "C" ) );

	PrintInputParameters( argc, argv );
	const unsigned int columnsCount = 10;
	const unsigned int rowsCount = 22;
	CGame game;
	game.Initialize( rowsCount, columnsCount );
	game.ShowGrid();
	game.StartGame();
	game.MainLoop();

	boost::log::core::get()->remove_all_sinks();
	return 0;
}
