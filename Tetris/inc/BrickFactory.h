#pragma once

#include "Brick.h"

namespace Tetris
{
	class CBrickFactory
	{
	public:
		static CBrick* GetBrick( const BrickTypes brickType );
		static CBrick* GetRandomBrick();
	private:
	};
}