#include <algorithm>

#include "Game.h"
#include "MultiPointFactory.h"

#include "MainGrid.h"
#include "MogeLibMain.h"

namespace Tetris
{
	using namespace Moge;
	CGame::CGame()
	{
	}

	CGame::~CGame()
	{
	}

	void CGame::initialize( const unsigned int rowsCount, const unsigned int columnsCount, const unsigned int winWidth, const unsigned int winHeight )
	{
		EngineManager::getEngine()->createScreen( Math::MultiPointFactory::create2d<unsigned int>( winWidth, winHeight ) );
		mainGrid.reset( new CMainGrid() );
        EngineManager::getEngine()->registerObserver( this );
		mainGrid->SetSize( rowsCount, columnsCount );
		StartGame();
	}

	void CGame::StartGame()
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
