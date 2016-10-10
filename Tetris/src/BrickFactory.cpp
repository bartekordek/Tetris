#include "BrickFactory.h"
#include <cstdlib> //rand
#include <ctime>

namespace Tetris
{
	Brick* CBrickFactory::GetBrick( const BrickTypes brickType )
	{
		if( BrickTypes::L == brickType )
		{
			return new CLBrick();
		}
		else if( BrickTypes::I == brickType )
		{
			return new CIBrick();
		}
		else if( BrickTypes::O == brickType )
		{
			return new COBrick();
		}
		else if( BrickTypes::S == brickType )
		{
			return new CSBrick();
		}
		else if( BrickTypes::T == brickType )
		{
			return new CTBrick();
		}
		return nullptr;
	}

	Brick* CBrickFactory::GetRandomBrick()
	{
		srand( static_cast<UInt> ( time( nullptr ) ) );
		int randomNumber = rand() % 5;
		return GetBrick( static_cast<BrickTypes>( randomNumber ) );
	}
}