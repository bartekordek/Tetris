#include <algorithm>
#include <memory>

#include "Game.h"
#include "CUL/Math/Vector3D.hpp"

#include "MogeLibMain.h"

using EngineManager = Moge::EngineManager;
using Directions = CUL::Math::Directions;
using namespace Tetris;

Game::Game( void )
{

}

Game::~Game( void )
{
    this->mainGrid.reset();
}

void Game::initialize( 
    cunt rowsCount, cunt columnsCount,
    cunt winWidth, cunt winHeight )
{
    Vector3Du winSize( winWidth, winHeight, 0 );
    Vector3Di winPos( 100, 100, 0 );
    this->m_window = EngineManager::getEngine()->createWindow( winSize, winPos );
    mainGrid.reset( new CMainGrid( this->m_window ) );
    EngineManager::getEngine()->registerKeyboardObserver( this );
    mainGrid->SetSize( rowsCount, columnsCount, 2, 2 );
    startGame();
}

void Game::startGame()const
{
    mainGrid->ReLeaseBrick();
}

void stringToLower( std::string& someString );

void Game::onKeyboardEvent( const IKey& key )
{
    std::string keyName = key.getKeyName();
    stringToLower( keyName );
    if( "q" == keyName && key.getKeyIsDown() )
    {
        m_quit = true;
        return;
    }

    if( key.getKeyIsDown() )
    {
        std::cout << "Key " << key.getKeyName() << " is down." << std::endl;

        if( "left" == keyName )
        {
            mainGrid->MoveActualBrick( Directions::L );
        }
        else if( "right" == keyName )
        {
            mainGrid->MoveActualBrick( Directions::R );
        }
        else if( "down" == keyName )
        {
            mainGrid->MoveActualBrick( Directions::D );
        }
        else if( "space" == keyName )
        {
            mainGrid->RotateActualBrick( true );
        }
    }
}

void stringToLower( std::string& someString )
{
    std::transform( 
        someString.begin(), 
        someString.end(), 
        someString.begin(), 
        ::tolower );
}

void Game::frontEndLoop()
{
    while( false == m_quit )
    {
        mainGrid->updateGrid();
    }
}