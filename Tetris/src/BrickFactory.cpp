#include "BrickFactory.h"
#include <cstdlib> //rand

namespace Tetris
{

	CBrick* CBrickFactory::GetBrick( const BrickTypes brickType )
	{
		if( L == brickType )
		{
			return new CLBrick();
		}
		else if( I == brickType )
		{
			return new CIBrick();
		}
		else if( O == brickType )
		{
			return new COBrick();
		}
		else if( S == brickType )
		{
			return new CSBrick();
		}
		else if( T == brickType )
		{
			return new CTBrick();
		}
		return NULL;
	}

	CBrick* CBrickFactory::GetRandomBrick()
	{
		srand( static_cast<UInt> ( time( NULL ) ) );
		int randomNumber = rand() % 5;
		return GetBrick( static_cast<BrickTypes>( randomNumber ) );
	}
}