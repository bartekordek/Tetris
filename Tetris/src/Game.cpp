#include "Game.h"
#include "BrickFactory.h"
#include "MTime.h"
#include "NodeCreator.h"
#include "MultiPointFactory.h"
#include "IPositionAdapter.h"
#include "NodeImageCreator.h"

#include <cstddef>

#include <SDL.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_events.h>

namespace Tetris
{
	CGame::CGame():
		m_roundInProgress( false ),
		m_quit( false )
	{
	}

	CGame::~CGame()
	{
	}

	Moge::ImageSurface CGame::GetEmptySlabSurface()const
	{
		return mEmptySlabImage;
	}

	Moge::ImageSurface CGame::GetFilledSlabSurface()const
	{
		return mFilledSlabImage;
	}

	void CGame::Initialize( CUInt rowsCount, CUInt columnsCount, const Resolution& resoltion )
	{
		Moge::Engine::Instance().CreateScreen( Moge::Math::MultiPointFactory::create2d<unsigned int>( 640, 480 ) );
		Moge::Engine::Instance().StartMainLoop();
		SetMainGridSize( rowsCount, columnsCount );
		SetMainGridFilledSlabImage();
		SetMainGridEmptySlabImage();
		CreateGrid();
	}

	void CGame::SetMainGridSize( CUInt rows, CUInt columns )
	{
		m_mainGrid.SetSize( rows, columns );
	}

	void CGame::SetMainGridFilledSlabImage()
	{
		Moge::Path blockImagepath = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\Block.bmp";
		mFilledSlabImage = Moge::ImageCreator::CreateSurfaceFromImage( blockImagepath );
	}

	void CGame::SetMainGridEmptySlabImage()
	{
		Moge::Path bgBlockImagepath = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
		mEmptySlabImage = Moge::ImageCreator::CreateSurfaceFromImage( bgBlockImagepath );
	}

	void CGame::CreateGrid()
	{		
		m_mainGrid.SetGamePtr( this );

		for( auto& slabRow : m_mainGrid.GetSlabs() )
		{
			for( auto& slab: slabRow )
			{
				std::shared_ptr<Moge::ObjectNodeContent> slabNode = Moge::NodeCreator::CreateFromImage( mEmptySlabImage );
				Moge::Math::IPositionAdapter<int> position( slab.Col() * slabNode->getWidth(), slab.Row() * slabNode->getHeight(), 0 );
				slabNode->setXyz( position.getX(), position.getY(), 0 );
				slab.SetNode( slabNode );

				slabNode->SetVisible();
				Moge::Engine::Instance().AddObject( slabNode );//TODO: redundant add, should be moved to NodeMgr
			}
		}
	}

	void CGame::StartGame()
	{
		ReleaseBrick();
		ShowGrid();
	}

	void CGame::MainLoop()
	{
		SDL_Event event;
		m_mainLoopThread = std::thread( &CGame::MainLoopThread, this );
		while( false == m_quit )
		{
			while( SDL_PollEvent( &event ) )
			{
				if( true == QuitHasBeenHit( event ) )
				{
					m_quit = true;
				}
				else if( IsKeyDown( event ) )
				{
					HandleKeys( event.key.keysym.sym );
				}
			}
		}
		m_mainLoopThread.join();
	}

	const bool CGame::IsKeyDown( const SDL_Event event )
	{
		if( SDL_KEYDOWN == event.type )
		{
			return true;
		}
		return false;
	}

	void CGame::HandleKeys( SDL_Keycode sdlkey )
	{
		if( SDLK_RIGHT == sdlkey )
		{
			MoveActiveBrick( COrientation::Direction::R );
		}
		else if( SDLK_LEFT == sdlkey )
		{
			MoveActiveBrick( COrientation::Direction::L );
		}
		else if( SDLK_DOWN == sdlkey )
		{
			MoveActiveBrick( COrientation::Direction::D );
		}
		else if( SDLK_SPACE == sdlkey )
		{
			RotateActualBrick();
		}
	}

	void CGame::MainLoopThread()
	{
		while( false == m_quit )
		{
			if( false == m_mainGrid.CheckIfBlockCanBeMoved( COrientation::Direction::D ) )
			{
				AddCurrentBrickToGrid();
				m_mainGrid.ManageFullLine();
				ReleaseBrick();
			}
			Moge::CTimeMod::SleepMiliSeconds( 500 );
			MoveActiveBrick( COrientation::Direction::D );
			//Moge::Engine::Instance().QueueFrame();
		}
	}

	void CGame::ReleaseBrick()
	{
		m_mainGrid.ReLeaseBrick();
		ShowGrid();
	}

	void CGame::ShowGrid()
	{
	}

	void CGame::AddCurrentBrickToGrid()
	{
		CBrick* currentBrick = m_mainGrid.GetCurrentBrick();
		if( currentBrick )
		{
			for( auto& coord : currentBrick->GetBlockPositions() )
			{
				CSlab& slab = m_mainGrid.GetSlab( coord.Row(), coord.Col() );
				slab.Empty( false );
				slab.GetNode().get()->SetSurface( mFilledSlabImage );
			}
		}
	}

	void CGame::MoveActiveBrick( const COrientation::Direction direction )
	{
		m_mainGrid.MoveActualBrick( direction );
		ActualizeGrid();
		ShowGrid();
	}

	void CGame::RotateActualBrick( const bool clockWise )
	{
		m_mainGrid.RotateActualBrick( clockWise );
	}

	void CGame::ActualizeGrid()
	{
	}

	const bool CGame::QuitHasBeenHit( const SDL_Event event )
	{
		if( event.type == SDL_QUIT || ( event.type == SDL_KEYDOWN && SDLK_q == event.key.keysym.sym ) )
		{
			return true;
		}
		return false;
	}
}