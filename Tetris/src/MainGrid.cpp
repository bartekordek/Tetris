#include "MainGrid.h"
#include <boost/foreach.hpp>

CMainGrid::CMainGrid( const unsigned int rowsCount, 
					  const unsigned int columnsCount, 
					  const unsigned int initialX, 
					  const unsigned int initialY )
{
	SetSize( rowsCount, columnsCount, initialX, initialY );
}

CMainGrid::~CMainGrid()
{

}

void CMainGrid::SetSize( const unsigned int rowsCount,
						 const unsigned int columnsCount, 
						 const unsigned int initialX, 
						 const unsigned int initialY )
{
	m_columnsCount = columnsCount;
	m_rowsCount = rowsCount;
	for( unsigned int i = 0; i < m_rowsCount; ++i )
	{
		for( unsigned int j = 0; j < m_columnsCount; ++j )
		{
			m_slab.push_back( CSlab( j + initialX, i + initialY ) );
		}
	}
}


void CMainGrid::SetBackgroundPicture( const Path& picLocation, 
									  const unsigned int width, 
									  const unsigned int height )
{
	m_slabBackground = CPicture( picLocation, width, height );
}

const unsigned int CMainGrid::GetRowsCount()const
{
	return m_rowsCount;
}

const unsigned int CMainGrid::GetColumnsCount()const
{
	return m_columnsCount;
}

const std::string CMainGrid::GetSlabPictureLoc( )const
{
	return m_slabBackground.GetImgLoc();
}

const unsigned int CMainGrid::GetImgWidth()const
{
	return 10;
}

const unsigned int CMainGrid::GetImgHeight()const
{
	return 10;
}

const unsigned int CMainGrid::GetSlabRow( const unsigned int column, const unsigned int row )const
{
	return GetSlabRow( row*column + column );
}

const unsigned int CMainGrid::GetSlabCol( const unsigned int column, const unsigned int row )const
{
	return GetSlabCol( row*column + column );
}

const unsigned int CMainGrid::GetSlabRow( const unsigned int slabIndex )const
{
	return m_slab.at( slabIndex ).Row();
}

const unsigned int CMainGrid::GetSlabCol( const unsigned int slabIndex )const
{
	return m_slab.at( slabIndex ).Col();
}