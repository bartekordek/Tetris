#ifndef __BRICK_FACT__
#define __BRICK_FACT__

#include "Brick.h"

/*
 * @brief Mini utility class to generate specific type of brick.
 * @details Can generate it randomly or by given enum item.
 */
class CBrickFactory
{
public:
	/*
	 * @brief Generates Brick by given enum item.
	 * @param[in] BrickTypes type of brick.
	 */
	static CBrick* GetBrick( const BrickTypes brickType );
	/*
	 * @brief Generates Brick randomly.
	 */
	static CBrick* GetRandomBrick();
private:
};

#endif 