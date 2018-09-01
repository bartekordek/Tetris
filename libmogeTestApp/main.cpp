#include "Game.h"

#include "CUL/ConsoleUtilities.hpp"

int main( int argc, char *argv[] )
{
    auto& cu = CUL::ConsoleUtilities::getInstance();
    cu.setArgs( argc, argv );
    cu.printInputParameters();
    Tetris::Game game;
    game.initialize( 22, 10 );
    game.run();
    return 0;
}
