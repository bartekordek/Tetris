#ifndef __BRICK_FACT__
#define __BRICK_FACT__

#include "Brick.h"

class CBrickFactory
{
public:
	static CBrick* GetBrick( const std::string& brickType );
private:
};

#endif 