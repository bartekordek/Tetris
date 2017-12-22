#include "BrickFactory.h"
#include <cstdlib> //rand
#include <ctime>

namespace Tetris
{
Brick* CBrickFactory::GetRandomBrick()
{
    srand( static_cast<unsigned int> ( time( nullptr ) ) );
    unsigned int enumSize = static_cast<unsigned int>(BrickTypes::ITEMS_COUNT) - 1;
    int randomNumber = rand() % enumSize;
    BrickTypes brickType = static_cast<BrickTypes>( randomNumber );
    Brick* result = new Brick( brickType );
    return result;
}

Moge::Math::SquareMatrix2D<int> CBrickFactory::createBrick( const BrickTypes brickType )
{
    Moge::Math::SquareMatrix2D<int> result( 4 );
    switch( brickType )
    {
    case BrickTypes::L:
        result( 0, 0 ) = 1;
        result( 1, 0 ) = 1;
        result( 2, 0 ) = 1;
        result( 2, 1 ) = 1;
        break;
    case BrickTypes::I:
        result( 0, 0 ) = 1;
        result( 0, 1 ) = 1;
        result( 0, 2 ) = 1;
        result( 0, 3 ) = 1;
        break;
    case BrickTypes::O:
        result( 0, 0 ) = 1;
        result( 0, 1 ) = 1;
        result( 1, 0 ) = 1;
        result( 1, 1 ) = 1;
        break;
    case BrickTypes::S:
        result( 1, 0 ) = 1;
        result( 1, 1 ) = 1;
        result( 0, 1 ) = 1;
        result( 0, 2 ) = 1;
        break;
    case BrickTypes::Z:
        result( 0, 0 ) = 1;
        result( 0, 1 ) = 1;
        result( 1, 1 ) = 1;
        result( 1, 2 ) = 1;
        break;
    case BrickTypes::T:
        result( 0, 0 ) = 1;
        result( 0, 1 ) = 1;
        result( 0, 2 ) = 1;
        result( 1, 1 ) = 1;
        break;
    default:
        result( 0, 0 ) = 1;
    }
    return result;
}
}