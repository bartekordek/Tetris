#include "Game.h"
#include "MainGrid.h"
#include "BrickFactory.h"
#include "CUL/ITimer.hpp"
#include "MogeLibMain.h"
#include "CUL/Math/Vector3D.hpp"
#include "CUL/Path.hpp"
#include <cmath>


using namespace Tetris;
using Path = CUL::FS::Path;
using Directions = CUL::Math::Directions;
using EngineManager = Moge::EngineManager;

CMainGrid::CMainGrid():
    runFunThread( true )
{
    this->timer.reset( CUL::TimerFactory::getChronoTimer() );

    this->tF = EngineManager::getEngine()->get2DTextureFactory();
    std::lock_guard<std::mutex> slabLock( currentBrickMutex );

    Path blockImagepath( "..\\Media\\Block.bmp" );
    this->filledSlabTex = tF->createTexture( blockImagepath );

    Path bgBlockImagepath( "..\\Media\\BackGroundBlock.bmp" );
    this->emptySlabTex = tF->createTexture( bgBlockImagepath );

    this->funThread = std::thread( &CMainGrid::funLoop, this );
}

CMainGrid::~CMainGrid()
{
    std::cout << "CMainGrid::~CMainGrid()\n";
    this->runFunThread = false;
    this->funThread.join();
}

void CMainGrid::updateGrid()
{
    if( false == checkIfBlockCanBeMoved( Directions::D ) )
    {
        addCurrentBrickToGrid();
        ManageFullLine();
        ReLeaseBrick();
    }
    this->timer->sleepMiliSeconds( 500 );
    MoveActualBrick( Directions::D );
}

void CMainGrid::SetSize( const unsigned int rowsCount, const unsigned int columnsCount, const unsigned int initialX, const unsigned int initialY )
{
    clearSlabs();
    for( unsigned row = 0; row < rowsCount; ++row )
    {
        SlabRow rows;
        for( unsigned col = 0; col < columnsCount; ++col )
        {
            Slab slab( row + initialY, col + initialX, true );
            rows.push_back( slab );
        }
        slabsRows.push_back( rows );
    }
    for( auto& slabRow : slabsRows )
    {
        for( auto& slab : slabRow )
        {
            auto slabNode = EngineManager::getEngine()->get2DNodeFactory()->createFromTexture( this->emptySlabTex );
            slabNode->setScale( CUL::Math::Vector3Dd( 2.0, 2.0, 0.0 ) );
            auto& slabSize = slabNode->getAbsSize();
            slabNode->setX( slab.col() * slabSize.getX() );
            slabNode->setY( slab.row() * slabSize.getY() );

            slab.setNode( slabNode );
            slabNode->SetVisible( true );
        }
    }
}

void CMainGrid::clearSlabs()
{
    this->slabsRows.erase( this->slabsRows.begin(), this->slabsRows.end() );
}

void CMainGrid::funLoop()
{
    std::cout << "CMainGrid::funLoop()::start\n";
    CUL::Math::Vector3Dd pos( 400.0, 20.0, 0.0 );
    auto slabNode = EngineManager::getEngine()->get2DNodeFactory()->createFromTexture( 
        this->emptySlabTex );
    slabNode->SetVisible( true );
    float t = 0.0;
    float x0 = 350;
    float y0 = 350;
    while( this->runFunThread )
    {
        std::cout << "CMainGrid::funLoop()iteration::start\n";
        pos.setX( x0 + 100 * cos( t ) );
        pos.setY( y0 + 100 * sin( t ) );
        slabNode->setPosition( pos );
        t += 0.1f;
        this->timer->sleepMiliSeconds( 16 );
        std::cout << "CMainGrid::funLoop()iteration::stop\n";
    }
    std::cout << "CMainGrid::funLoop()::stop\n";
}

void CMainGrid::ReLeaseBrick()
{
    this->activeBrick.reset( CBrickFactory::GetRandomBrick() );
    AddBrick( this->activeBrick.get() );
}

void CMainGrid::AddBrick( const Brick* brick )
{
    const CoordinatestList coords = brick->getBlockPositions();
    for( auto it = coords.begin(); it != coords.end(); ++it )
    {
        MarkSlabAsPartOfMovingBlock( it->getRow(), it->getCol() );
    }
}

void CMainGrid::MarkSlabAsPartOfMovingBlock( const unsigned int row, const unsigned int col )
{
    if( row >= slabsRows.size() || ( slabsRows.size() > 0 && col > slabsRows.at( 0 ).size() ) )
    {
        return;
    }
    Slab& slab = slabsRows.at( row ).at( col );
    slab.setEmpty( false );
    slab.getNode()->setTexture( this->filledSlabTex );
}

const bool CMainGrid::PartOfCurrentBrick( 
    const unsigned int rowIndex, 
    const unsigned int colIndex )const
{
    CoordinatestList coords = activeBrick->getBlockPositions();
    for( auto it = coords.begin(); it != coords.end(); ++it )
    {
        if( it->getRow() == rowIndex && it->getCol() == colIndex )
        {
            return true;
        }
    }
    return false;
}

void CMainGrid::MoveActualBrick( 
    const Directions direction )
{
    if( checkIfBlockCanBeMoved( direction ) )
    {
        m_RemoveActualBlockSlabsFromGrid();
        moveCurrentBrick( direction );
    }
}

const bool CMainGrid::checkIfBlockCanBeMoved( const Directions direction )
{
    for( auto& coord : activeBrick->getBlockPositions() )
    {
        const unsigned int newRow = coord.getRow() + GetRowOffset( direction );
        const unsigned int newCol = coord.getCol() + GetColOffset( direction );

        if( newRow >= slabsRows.size() )
        {
            return false;
        }

        if( false == SlabExist( newRow, newCol) ) 
        {
            return false;
        }

        if( true == PartOfCurrentBrick( newRow, newCol ) )
        {
            continue;
        }

        if( false == slabsRows.at( newRow ).at( newCol ).isEmpty() )
        {
            return false;
        }
    }
    return true;
}

const int CMainGrid::GetColOffset( const Directions direction )const
{
    if( Directions::U == direction || Directions::D == direction )
    {
        return 0;
    }

    if( Directions::R == direction )
    {
        return 1;
    }
    if( Directions::L == direction )
    {
        return  -1;
    }
    return -1;
}

const int CMainGrid::GetRowOffset( const Directions direction )const
{
    if( Directions::U == direction )
    {
        return  0;
    }
    if( Directions::D == direction )
    {
        return  1;
    }
    if( Directions::R == direction )
    {
        return  0;
    }
    if( Directions::L == direction )
    {
        return  0;
    }
    return -1;
}

void CMainGrid::RotateActualBrick( const bool clockWise )
{
    Brick* tempBrick = new Brick( *activeBrick );
    tempBrick->rotate( clockWise );
    if( true == m_CheckIfBlockCanBePlaced( tempBrick ) )
    {
        m_RemoveActualBlockSlabsFromGrid();
        activeBrick->rotate( clockWise );
    }
    delete tempBrick;
}

void CMainGrid::addCurrentBrickToGrid()
{
    if( nullptr != this->activeBrick.get() )
    {
        for( auto& coord : this->activeBrick->getBlockPositions() )
        {
            Slab& slab = slabsRows.at( coord.getRow() ).at( coord.getCol() );
            slab.setEmpty( false );
            slab.getNode()->setTexture( this->filledSlabTex );
        }
    }
}

const bool CMainGrid::m_CheckIfBlockCanBePlaced( const Brick* brick )
{
    CoordinatestList coords = brick->getBlockPositions();
    for( auto it = coords.begin(); it != coords.end(); ++it )
    {
        if( it->getRow() >= slabsRows.size() )
        {
            return false;
        }

        if( false == SlabExist( it->getRow(), it->getCol() ) )
        {
            return false;
        }

        if( true == PartOfCurrentBrick( it->getRow(), it->getCol() ) )
        {
            continue;
        }

        if( false == slabsRows.at( it->getRow() ).at( it->getCol() ).isEmpty() )
        {
            return false;
        }
    }
    return true;
}

const bool CMainGrid::SlabExist( const unsigned int rowIndex, const unsigned int colIndex )const
{
    if( colIndex >= slabsRows.at( 0 ).size() || rowIndex >= slabsRows.size() )
    {
        return false;
    }
    return true;
}

void CMainGrid::m_RemoveActualBlockSlabsFromGrid()
{
    for( auto& coord : this->activeBrick->getBlockPositions() )
    {
        auto& slab = slabsRows.at( coord.getRow() ).at( coord.getCol() );
        slab.setEmpty( true );
        slab.getNode()->setTexture( emptySlabTex );
    }
}

void CMainGrid::moveCurrentBrick( const Directions direction )
{
    this->activeBrick->move( direction );
    AddBrick( this->activeBrick.get() );
}

void CMainGrid::ManageFullLine()
{
    for( Slabs::iterator rowsIterator = slabsRows.begin(); rowsIterator != slabsRows.end(); ++rowsIterator )
    {
        SlabRow& slabRow = *rowsIterator;
        if( RowIsConnected( slabRow ) )
        {
            MoveAllLinesOneLineDown( rowsIterator );
        }
    }
}

const bool CMainGrid::RowIsConnected( const SlabRow& slabRow )const
{
    for( auto& slab : slabRow )
    {
        if( slab.isEmpty() )
        {
            return false;
        }
    }
    return true;
}

void CMainGrid::MoveAllLinesOneLineDown( 
    Slabs::iterator rowIterator )
{
    for( ; rowIterator != slabsRows.begin() + 1; --rowIterator )
    {
        auto& currentRow = *rowIterator;
        auto& oneRowHigher = *(rowIterator - 1);

        for( unsigned columnIterator = 0; columnIterator < currentRow.size(); ++columnIterator )
        {
            Slab& slabHigher = oneRowHigher.at( columnIterator );
            Slab& slabLower = currentRow.at( columnIterator );
            bool emptiness = slabHigher.isEmpty();
            slabLower.setEmpty( emptiness );
            SetSlabImagSurface( slabLower );
        }
    }

    for( unsigned int j = 0; j < rowIterator->size(); ++j )
    {
        Slab& slab = slabsRows.at( 0 ).at( j );
        slab.setEmpty( true );
        SetSlabImagSurface( slab );
    }
}

void CMainGrid::SetSlabImagSurface( Slab& slab )
{
    auto& slabNode = slab.getNode();
    if( slab.isEmpty() )
    {
        slabNode->setTexture( this->emptySlabTex );
    }
    else
    {
        slabNode->setTexture( this->filledSlabTex );
    }
}