#ifndef __BRICK_FACT__
#define __BRICK_FACT__

#include "Brick.h"

/*
 * @brief This class contains information about smallest part of game grid, which is slab. Slabs are parts of bricks.
 * @details
 */
class CBrickFactory
{
public:
	static CBrick* GetBrick( const BrickTypes brickType );
	static CBrick* GetRandomBrick();
private:
};

#endif 