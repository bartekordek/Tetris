#include "Game.h"

int main( void )
{
	const unsigned int initialXboardSize = 10;
	const unsigned int initialYBoardSize = 50;
	CGame::Instance()->Initialize( initialXboardSize, initialYBoardSize );
	CGame::Instance()->CreateWindow();
	CGame::Instance()->MainLoop();	
	CGame::Instance()->Destroy();
	return 0;
}