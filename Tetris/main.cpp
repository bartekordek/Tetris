#include "Game.h"

int main( void )
{
	const unsigned int columnsCount = 10;
	const unsigned int rowsCount = 22;
	CGame::Instance()->Initialize( rowsCount, columnsCount );
	CGame::Instance()->CreateWindow();
	CGame::Instance()->ShowGrid();
	CGame::Instance()->MainLoop();	
	CGame::Instance()->Destroy();
	return 0;
}