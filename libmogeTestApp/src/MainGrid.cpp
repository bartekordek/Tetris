#include "Game.h"
#include "MainGrid.h"
#include "BrickFactory.h"
#include "CUL/ITimer.hpp"
#include "MogeLibMain.h"
#include "CUL/Math/Vector3D.hpp"
#include "CUL/Path.hpp"
#include "CUL/SimpleAssert.hpp"
#include <cmath>


using namespace Tetris;
using Path = CUL::FS::Path;
using EngineManager = Moge::EngineManager;

CMainGrid::CMainGrid( Moge::IWindow* window ):
    runFunThread( true ),
    m_window( window )
{
    m_viewData.setDisplayOffset( Vector3dd( 0, 0 ,0 ) );
    m_viewData.setTargetSlabSize( Vector3dd( 20, 20, 0 ) );

    this->timer.reset( CUL::TimerFactory::getChronoTimer() );

    std::lock_guard<std::mutex> slabLock( currentBrickMutex );

    this->brickSlabTex = this->m_window->createTexture( "..\\Media\\red_block.bmp" );
    this->emptySlabTex = this->m_window->createTexture( "..\\Media\\white_block.bmp" );
    CUL::Assert::simple( this->brickSlabTex != this->emptySlabTex );

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

void CMainGrid::SetSize( 
    cunt rowsCount, cunt columnsCount,
    cunt initialX, cunt initialY )
{
    clearSlabs();
    for( unsigned row = 0; row < rowsCount; ++row )
    {
        SlabRow rows;
        for( unsigned col = 0; col < columnsCount; ++col )
        {
            Slab slab( row + initialY, col + initialX, true );
            slab.setViewData( &this->m_viewData );

            auto slabNode = this->m_window->createSprite( this->emptySlabTex );
            slabNode->SetVisible();
            slab.setNode( slabNode );

            rows.push_back( slab );
        }
        slabsRows.push_back( rows );
    }
}

void CMainGrid::clearSlabs()
{
    this->slabsRows.erase( this->slabsRows.begin(), this->slabsRows.end() );
}

void CMainGrid::funLoop()
{
    CUL::Math::Vector3Dd pos( 400.0, 20.0, 0.0 );
    CUL::Math::Vector3Dd scale( 1.0, 1.0, 1.0 );
    auto slabNode = this->m_window->createSprite( this->emptySlabTex );
    slabNode->SetVisible( true );
    float t = 0.0;
    float x0 = 350;
    float y0 = 350;
    double maxSize = 8.0;
    while( this->runFunThread )
    {
        scale.setXYZ
        (
            maxSize * (1.0 + sin( t )),
            maxSize * (1.0 + cos( t )),
            1.0
        );
        pos.setX( x0 + 100 * cos( t ) );
        pos.setY( y0 + 100 * sin( t ) );
        slabNode->setPosition( pos );
        slabNode->setScale( scale );
        t += 0.1f;
        this->timer->sleepMiliSeconds( 16 );
    }
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
        MarkSlabAsPartOfMovingBlock( it->getY(), it->getX() );
    }
}

void CMainGrid::MarkSlabAsPartOfMovingBlock( cunt row, cunt col )
{
    if( 
        row >= slabsRows.size() || 
        ( slabsRows.size() > 0 && col > slabsRows.at( 0 ).size() ) )
    {
        return;
    }
    Slab& slab = slabsRows.at( row ).at( col );
    slab.setEmpty( false );
    slab.getNode()->setTexture( this->brickSlabTex );
}

const bool CMainGrid::PartOfCurrentBrick( 
    cunt rowIndex, 
    cunt colIndex )const
{
    CoordinatestList coords = activeBrick->getBlockPositions();
    for( auto it = coords.begin(); it != coords.end(); ++it )
    {
        if( it->getY() == rowIndex && it->getX() == colIndex )
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
        cunt newRow = coord.getY() + getYOffset( direction );
        cunt newCol = coord.getX() + getXOffset( direction );

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

const int CMainGrid::getXOffset( const Directions direction )const
{
    if( Directions::U == direction || Directions::D == direction )
    {
        return 0;
    }

    if( Directions::R == direction )
    {
        return 1;
    }
    return -1;
}

const int CMainGrid::getYOffset( const Directions direction )const
{
    if( Directions::D == direction )
    {
        return  1;
    }
    return 0;
}

void CMainGrid::RotateActualBrick( const bool clockWise )
{
    Brick tempBrick( *activeBrick );
    tempBrick.rotate( clockWise );
    if( true == m_CheckIfBlockCanBePlaced( tempBrick ) )
    {
        m_RemoveActualBlockSlabsFromGrid();
        activeBrick->rotate( clockWise );
    }
}

void CMainGrid::addCurrentBrickToGrid()
{
    if( nullptr != this->activeBrick.get() )
    {
        for( auto& coord : this->activeBrick->getBlockPositions() )
        {
            Slab& slab = slabsRows.at( coord.getY() ).at( coord.getX() );
            slab.setEmpty( false );
            slab.getNode()->setTexture( this->brickSlabTex );
        }
    }
}

const bool CMainGrid::m_CheckIfBlockCanBePlaced( const Brick& brick )
{
    CoordinatestList coords = brick.getBlockPositions();
    for( auto it = coords.begin(); it != coords.end(); ++it )
    {
        if( it->getY() >= slabsRows.size() )
        {
            return false;
        }

        if( false == SlabExist( it->getY(), it->getX() ) )
        {
            return false;
        }

        if( true == PartOfCurrentBrick( it->getY(), it->getX() ) )
        {
            continue;
        }

        if( false == slabsRows.at( it->getY() ).at( it->getX() ).isEmpty() )
        {
            return false;
        }
    }
    return true;
}

const bool CMainGrid::SlabExist( cunt rowIndex, cunt colIndex )const
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
        auto& slab = slabsRows.at( coord.getY() ).at( coord.getX() );
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
    auto slabNode = slab.getNode();
    if( slab.isEmpty() )
    {
        slabNode->setTexture( this->emptySlabTex );
    }
    else
    {
        slabNode->setTexture( this->brickSlabTex );
    }
}
