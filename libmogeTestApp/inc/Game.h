#pragma once

#include <memory>
#include "IMogeApp.h"
#include "MainGrid.h"
namespace Tetris
{
    class CMainGrid;
    using IKey = Moge::IKey;
    class CGame: public Moge::IMogeApp
    {
    public:
        CGame( void );
        virtual ~CGame( void );
        void initialize( const unsigned int rowsCount = 50, const unsigned int columnsCount = 10, const unsigned int winWidth = 800, const unsigned int winHeight = 600 );
        void startGame()const;
        void keyboardEvent( IKey* data = nullptr ) override;

    private:
        void frontEndLoop() override;

        Moge::IWindow* m_window = nullptr;
        std::unique_ptr<CMainGrid> mainGrid;
        bool m_quit = false;
    };
}