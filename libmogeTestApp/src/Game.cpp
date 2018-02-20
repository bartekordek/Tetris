#include <algorithm>
#include <memory>

#include "Game.h"
#include "CUL/Math/Vector3D.hpp"

#include "MogeLibMain.h"

using EngineManager = Moge::EngineManager;
using Directions = CUL::Math::Directions;
using namespace Tetris;

CGame::CGame( void )
{

}

CGame::~CGame( void )
{
    this->mainGrid.reset();
}

void CGame::initialize( 
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

void CGame::startGame()const
{
    mainGrid->ReLeaseBrick();
}

void stringToLower( std::string& someString );

void CGame::onKeyboardEvent( const IKey& key )
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

void CGame::frontEndLoop()
{
    while( false == m_quit )
    {
        mainGrid->updateGrid();
    }
}