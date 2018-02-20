#pragma once

#include "IMogeApp.h"
#include "MainGrid.h"

#include "CUL/LckPrim.hpp"

#include <memory>

namespace Tetris
{
    class CMainGrid;
    using IKey = Moge::IKey;
    using cunt = const unsigned int;
    using Vector3Du = CUL::Math::Vector3Du;
    using Vector3Di = CUL::Math::Vector3Di;
    class CGame: public Moge::IMogeApp
    {
    public:
        CGame( void );
        virtual ~CGame( void );
        void initialize(
            cunt rowsCount = 50, cunt columnsCount = 10,
            cunt winWidth = 800, cunt winHeight = 600 );
        void startGame()const;
        void onKeyboardEvent( const IKey& data ) override;

    private:
        void frontEndLoop() override;

        Moge::IWindow* m_window = nullptr;
        std::unique_ptr<CMainGrid> mainGrid;
        CUL::LckPrim<bool> m_quit{ false };
    };
}