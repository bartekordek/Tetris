#pragma once

#include <memory>
#include "IMogeApp.h"

namespace Tetris
{
	class CMainGrid;
	class CGame: public Moge::IMogeApp
	{
	public:
		CGame();
		void initialize( const unsigned int rowsCount = 50, const unsigned int columnsCount = 10, const unsigned int winWidth = 640, const unsigned int winHeight = 480 );
		void StartGame();
		void keyboardEvent( Moge::IKey* data = nullptr ) override;
		virtual ~CGame();

	private:
		void userInputLoop();
		void frontEndLoop() override;

		std::unique_ptr<CMainGrid> mainGrid;
		bool m_quit = false;
	};
}