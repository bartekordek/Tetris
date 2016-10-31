#include "BrickFactory.h"
#include <cstdlib> //rand
#include <ctime>

namespace Tetris
{
	Brick* CBrickFactory::GetBrick( const BrickTypes brickType )
	{
		switch( brickType )
		{
		case BrickTypes::L:
			return new CLBrick();
		case BrickTypes::I:
			return new CIBrick();
		case BrickTypes::O:
			return new COBrick();
		case BrickTypes::S:
			return new CSBrick();
		case BrickTypes::T:
			return new CTBrick();
		default:
			return nullptr;
		}
	}

	Brick* CBrickFactory::GetRandomBrick()
	{
		srand( static_cast<UInt> ( time( nullptr ) ) );
		int randomNumber = rand() % 5;
		return GetBrick( static_cast<BrickTypes>( randomNumber ) );
	}
}