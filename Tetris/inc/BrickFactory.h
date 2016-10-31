#pragma once

#include "Brick.h"
#include "SquareMatrix2D.hpp"

namespace Tetris
{
class CBrickFactory
{
public:
	static Brick* GetBrick( const BrickTypes brickType );
	static Brick* GetRandomBrick();
	static Moge::Math::SquareMatrix2D<int> createBrick( const BrickTypes brickType );
private:
};
}