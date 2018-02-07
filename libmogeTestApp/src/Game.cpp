#include <algorithm>
#include <memory>

#include "Game.h"
#include "CUL/Math/Vector3D.hpp"

#include "MogeLibMain.h"

using EngineManager = Moge::EngineManager;
using Directions = CUL::Math::Directions;
using IKey = Moge::IKey;

using namespace Tetris;

CGame::~CGame()
{
    this->mainGrid.reset();
}

void CGame::initialize( const unsigned int rowsCount, const unsigned int columnsCount, const unsigned int winWidth, const unsigned int winHeight )
{
    auto winSize = CUL::Math::Vector3Du( winWidth, winHeight, 0 );
    CUL::Math::Vector3Di winPos( 100, 100, 0 );
    EngineManager::getEngine()->createWindow( winSize, winPos );
    mainGrid.reset( new CMainGrid() );
    EngineManager::getEngine()->registerObserver( this );
    mainGrid->SetSize( rowsCount, columnsCount );
    startGame();
}

void CGame::startGame()const
{
    mainGrid->ReLeaseBrick();
}

void stringToLower( std::string& someString );

void CGame::keyboardEvent( IKey* data )
{
    std::string keyName = data->getKeyName();
    stringToLower( keyName );
    if( "q" == keyName && data->getKeyIsDown() )
    {
        m_quit = true;
        return;
    }

    if( data->getKeyIsDown() )
    {
        std::cout << "Key " << data->getKeyName() << " is down." << std::endl;

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