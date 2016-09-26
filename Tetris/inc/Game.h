#pragma once

#include "MainGrid.h"
#include "Brick.h"
#include <Engine.h>
#include <MyString.h>
#include <SDL_keycode.h>

union SDL_Event;

namespace Tetris
{

	struct Resolution
	{
		Resolution( const unsigned int width, const unsigned int height ):
			width( width ),
			height( height )
		{

		}
		unsigned int width;
		unsigned int height;
	};

	class CGame
	{
	public:
		CGame();
		void Initialize( CUInt rowsCount = 50, CUInt columnsCount = 10, const Resolution& resoltion = Resolution( 640, 480 ) );
		void ShowGrid();
		void MainLoop();
		void StartGame();
		virtual ~CGame();

		Moge::ImageSurface GetEmptySlabSurface()const;
		Moge::ImageSurface GetFilledSlabSurface()const;

	private:
		void SetMainGridEmptySlabImage();
		void SetMainGridFilledSlabImage();
		void CreateGrid();
		const bool QuitHasBeenHit( const SDL_Event event );
		const bool IsKeyDown( const SDL_Event event );
		void HandleKeys( SDL_Keycode sdlkey );
		void SetMainGridSize( CUInt rows, CUInt columns );
		void MoveActiveBrick( const COrientation::Direction direction = COrientation::Direction::D );
		void RotateActualBrick( const bool clockWise = true );
		void ReleaseBrick();
		void ActualizeGrid();
		void AddCurrentBrickToGrid();
		void MainLoopThread();

		Moge::ImageSurface mEmptySlabImage;
		Moge::ImageSurface mFilledSlabImage;

		CMainGrid m_mainGrid;
		std::thread m_mainLoopThread;
		bool m_roundInProgress;
		bool m_quit;

		Moge::MyString emptySlabName = Moge::MyString( "emptySlab" );
		Moge::MyString slabName = Moge::MyString( "slab" );
	};
}