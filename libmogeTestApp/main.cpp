#include "Game.h"

#include "CUL/ConsoleUtilities.hpp"

int main( int argc, char *argv[] )
{
    CUL::ConsoleUtilities::PrintInputParameters( argc, argv );
    Tetris::CGame game;
    game.initialize( 22, 10 );
    game.run();
    return 0;
}
