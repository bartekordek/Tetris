#pragma once 

#include "ViewData.hpp"

#include "Slab.h"
#include "Brick.h"
#include "CUL/LckPrim.hpp"
#include "CUL/ITimer.hpp"
#include "INode.h"

#include "IWindow.hpp"

#include <vector>
#include <mutex>
#include <memory>

namespace Tetris
{
    using SlabRow = std::vector<Slab>;
    using Slabs = std::vector<SlabRow>;
    using Directions = CUL::Math::Directions;
    class CMainGrid
    {
    public:
        CMainGrid( Moge::IWindow* window );
        virtual ~CMainGrid();
        void updateGrid();
        void SetSize( 
            cunt rowsCount, 
            cunt columnsCount, 
            cunt initialX = 0, 
            cunt initialY = 0 );
        
        void ReLeaseBrick();
        void MoveActualBrick( const Directions direction );
        void RotateActualBrick( const bool clockWise = true );

    private:
        void AddBrick( const Brick* brick );
        const bool SlabExist( cunt rowIndex, cunt colIndex )const;
        const bool PartOfCurrentBrick( cunt rowIndex, cunt colIndex )const;
        const bool checkIfBlockCanBeMoved( const Directions direction );
        void addCurrentBrickToGrid();
        void ManageFullLine();
        const int getXOffset( const Directions direction )const;
        const int getYOffset( const Directions direction )const;
        void moveCurrentBrick( const Directions direction );
        void m_RemoveActualBlockSlabsFromGrid();
        void MarkSlabAsPartOfMovingBlock( cunt row, cunt col );
        const bool RowIsConnected( const SlabRow& slabRow )const;
        const bool m_CheckIfBlockCanBePlaced( const Brick& brick );
        void MoveAllLinesOneLineDown( Slabs::iterator rowIterator );
        void SetSlabImagSurface( Slab& slab );
        void clearSlabs();
        void funLoop();
        std::thread funThread;
        CUL::LckPrim<bool> runFunThread;

        std::unique_ptr<Brick> activeBrick;
        Slabs slabsRows;
        std::mutex slabsMutex;
        std::mutex currentBrickMutex;
        Moge::ITexture* emptySlabTex;
        Moge::ITexture* brickSlabTex;
        std::unique_ptr<CUL::ITimer> timer;

        Moge::IWindow* m_window = nullptr;
        ViewData m_viewData;
    };
}