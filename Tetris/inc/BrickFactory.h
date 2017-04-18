#pragma once

#include "Brick.h"
#include "Math/SquareMatrix2D.hpp"

namespace Tetris
{
class CBrickFactory
{
public:
	static Brick* GetRandomBrick();
	static Moge::Math::SquareMatrix2D<int> createBrick( const BrickTypes brickType );
private:
};
}