#pragma once 

#include "Slab.h"
#include "Brick.h"
#include "CUL/LckPrim.hpp"
#include "CUL/ITimer.hpp"
#include "INode.h"
#include <vector>
#include <mutex>
#include <memory>

namespace Tetris
{
    using SlabRow = std::vector<Slab>;
    using Slabs = std::vector<SlabRow>;
    class CMainGrid
    {
    public:
        CMainGrid( Moge::IWindow* window );
        virtual ~CMainGrid();
        void updateGrid();
        void SetSize( 
            const unsigned int rowsCount, 
            const unsigned int columnsCount, 
            const unsigned int initialX = 0, 
            const unsigned int initialY = 0 );
        
        void ReLeaseBrick();
        void MoveActualBrick( const CUL::Math::Directions direction );
        void RotateActualBrick( const bool clockWise = true );

    private:
        void AddBrick( const Brick* brick );
        const bool SlabExist( const unsigned int rowIndex, const unsigned int colIndex )const;
        const bool PartOfCurrentBrick( const unsigned int rowIndex, const unsigned int colIndex )const;
        const bool checkIfBlockCanBeMoved( const CUL::Math::Directions direction );
        void addCurrentBrickToGrid();
        void ManageFullLine();
        const int GetColOffset( const CUL::Math::Directions direction )const;
        const int GetRowOffset( const CUL::Math::Directions direction )const;
        void moveCurrentBrick( const CUL::Math::Directions direction );
        void m_RemoveActualBlockSlabsFromGrid();
        void MarkSlabAsPartOfMovingBlock( const unsigned int row, const unsigned int col );
        const bool RowIsConnected( const SlabRow& slabRow )const;
        const bool m_CheckIfBlockCanBePlaced( const Brick* brick );
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
        Moge::ITexture* filledSlabTex;
        std::unique_ptr<CUL::ITimer> timer;

        Moge::IWindow* m_window = nullptr;
    };
}