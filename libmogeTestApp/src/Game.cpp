#include <algorithm>
#include <memory>

#include "Game.h"
#include "Math/IPositionFactory.h"
#include "Math/SizeUInt2D.h"

#include "MogeLibMain.h"

namespace Tetris
{
    CGame::~CGame()
    {
        this->mainGrid.reset();
    }

    using namespace Moge;
    using namespace Math;
    void CGame::initialize( const unsigned int rowsCount, const unsigned int columnsCount, const unsigned int winWidth, const unsigned int winHeight )
    {
        auto winSize = SizeUint2D( winWidth, winHeight );
        std::unique_ptr<IPosition<int>> winPos( IPositionFactory::createPositionInt2D( 100, 100 ) );
        EngineManager::getEngine()->createScreen( winSize, *winPos );
        mainGrid.reset( new CMainGrid() );
        EngineManager::getEngine()->registerObserver( this );
        mainGrid->SetSize( rowsCount, columnsCount );
        startGame();
    }

    void CGame::startGame()const
    {
        mainGrid->ReLeaseBrick();
    }

    void CGame::keyboardEvent( IKey* data )
    {
        std::string keyName = data->getKeyName();
        std::transform( keyName.begin(), keyName.end(), keyName.begin(), ::tolower );
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
                mainGrid->MoveActualBrick( Math::Directions::L );
            }
            else if( "right" == keyName )
            {
                mainGrid->MoveActualBrick( Math::Directions::R );
            }
            else if( "down" == keyName )
            {
                mainGrid->MoveActualBrick( Math::Directions::D );
            }
            else if( "space" == keyName )
            {
                mainGrid->RotateActualBrick( true );
            }
        }
    }
    void CGame::frontEndLoop()
    {
        while( false == m_quit )
        {
            mainGrid->updateGrid();
        }
    }
}
