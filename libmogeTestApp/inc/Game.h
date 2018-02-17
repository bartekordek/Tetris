#pragma once

#include <memory>
#include "IMogeApp.h"
#include "MainGrid.h"
namespace Tetris
{
    class CMainGrid;
    using IKey = Moge::IKey;
    using cunt = const unsigned int;
    class CGame: public Moge::IMogeApp
    {
    public:
        CGame( void );
        virtual ~CGame( void );
        void initialize(
            cunt rowsCount = 50, cunt columnsCount = 10,
            cunt winWidth = 800, cunt winHeight = 600 );
        void startGame()const;
        void keyboardEvent( IKey* data = nullptr ) override;

    private:
        void frontEndLoop() override;

        Moge::IWindow* m_window = nullptr;
        std::unique_ptr<CMainGrid> mainGrid;
        bool m_quit = false;
    };
}