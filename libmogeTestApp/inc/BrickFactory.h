#pragma once

#include "Brick.h"
#include "CUL/Math/SquareMatrix2D.hpp"

namespace Tetris
{
class CBrickFactory
{
public:
    static Brick* GetRandomBrick();
    static CUL::Math::SquareMatrix2Di createBrick( const BrickTypes brickType );
private:
};
}