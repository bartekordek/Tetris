#pragma once

#include "MainGrid.h"
#include <Engine.h>
#include "IKeyboardObserver.h"
#include <SDL_keycode.h>

union SDL_Event;

namespace Tetris
{
	class CGame: public Moge::IKeyboardObserver
	{
	public:
		CGame();
		void initialize( CUInt rowsCount = 50, CUInt columnsCount = 10, CUInt winWidth = 640, CUInt winHeight = 480 );
		void MainLoop();
		void StartGame();
		void keyboardEvent( Moge::IObservableData* data ) override;
		virtual ~CGame();

	private:
		void userInputLoop();
		static const bool QuitHasBeenHit( const SDL_Event event );
		static const bool IsKeyDown( const SDL_Event event );
		void HandleKeys( SDL_Keycode sdlkey );
		void MainLoopThread();

		CMainGrid* m_mainGrid = nullptr;
		std::thread m_mainLoopThread;
		bool m_quit = false;
	};
}