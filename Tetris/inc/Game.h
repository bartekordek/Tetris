#pragma once

#include "MainGrid.h"
#include "Brick.h"
#include <Engine.h>
#include <MyString.h>
#include <SDL_keycode.h>

union SDL_Event;

namespace Tetris
{
	class CGame
	{
	public:
		CGame();
		void initialize( CUInt rowsCount = 50, CUInt columnsCount = 10, CUInt winWidth = 640, CUInt winHeight = 480 );
		void MainLoop();
		void StartGame();
		virtual ~CGame();

	private:
		void userInputLoop();
		const bool QuitHasBeenHit( const SDL_Event event );
		const bool IsKeyDown( const SDL_Event event );
		void HandleKeys( SDL_Keycode sdlkey );
		void MainLoopThread();

		CMainGrid m_mainGrid;
		std::thread m_mainLoopThread;
		bool m_quit = false;
	};
}