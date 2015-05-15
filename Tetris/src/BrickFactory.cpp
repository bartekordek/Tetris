#include "BrickFactory.h"

CBrick* CBrickFactory::GetBrick( const std::string& brickType )
{
	if( "L" == brickType )
	{
		return new CLBrick();
	}
	else if( "I" == brickType )
	{
		return new CIBrick();
	}
	else if( "O" == brickType )
	{
		return new COBrick();
	}
	else if( "S" == brickType )
	{
		return new CSBrick();
	}
	else if( "T" == brickType )
	{
		return new CTBrick();
	}
	return NULL;

}