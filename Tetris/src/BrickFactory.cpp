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

Moge::Math::SquareMatrix2D<int> CBrickFactory::createBrick( const BrickTypes brickType )
{
	Moge::Math::SquareMatrix2D<int> result( 4 );
	switch( brickType )
	{
	case BrickTypes::L:
		result( 0, 0 ) = 1;
		result( 1, 0 ) = 1;
		result( 2, 0 ) = 1;
		result( 2, 1 ) = 1;
		break;
	case BrickTypes::I:
		result( 0, 0 ) = 1;
		result( 0, 1 ) = 1;
		result( 0, 2 ) = 1;
		result( 0, 3 ) = 1;
		break;
	case BrickTypes::O:
		result( 0, 0 ) = 1;
		result( 0, 1 ) = 1;
		result( 1, 0 ) = 1;
		result( 1, 1 ) = 1;
		break;
	case BrickTypes::S:
		result( 1, 0 ) = 1;
		result( 1, 1 ) = 1;
		result( 0, 1 ) = 1;
		result( 0, 2 ) = 1;
		break;
	case BrickTypes::Z:
		result( 0, 0 ) = 1;
		result( 0, 1 ) = 1;
		result( 1, 1 ) = 1;
		result( 1, 2 ) = 1;
		break;
	case BrickTypes::T:
		result( 0, 0 ) = 1;
		result( 0, 1 ) = 1;
		result( 0, 2 ) = 1;
		result( 1, 1 ) = 1;
		break;
	}
	return result;
}
}