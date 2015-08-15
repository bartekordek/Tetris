#include "inc/Game.h"

int main( int argc, char *argv[] )
{
	const unsigned int columnsCount = 10;
	const unsigned int rowsCount = 22;
	CGame::Instance().Initialize( rowsCount, columnsCount );
	CGame::Instance().InitWindow();
	CGame::Instance().ShowGrid();
	CGame::Instance().StartGame();
	CGame::Instance().MainLoop();
	CGame::Instance().Destroy();
	return 0;
}
