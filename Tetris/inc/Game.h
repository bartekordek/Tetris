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
		void initialize( CUInt rowsCount = 50, CUInt columnsCount = 10, CUInt winWidth = 640, CUInt winHeight = 480 );
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