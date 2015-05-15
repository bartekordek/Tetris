#include "MainGrid.h"
#include <boost/foreach.hpp>

CMainGrid::CMainGrid( 
	const unsigned int rowsCount, 
	const unsigned int columnsCount, 
	const unsigned int initialX, 
	const unsigned int initialY )
{
	SetSize( rowsCount, columnsCount, initialX, initialY );
}

CMainGrid::~CMainGrid()
{

}

void CMainGrid::SetSize( 
	const unsigned int rowsCount,
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

void CMainGrid::SetBackgroundPicture( const boost::filesystem::path& picLocation, const unsigned int width, const unsigned int height )
{
	BOOST_FOREACH( CSlab& slab, m_slab )
	{
		slab.SetPicture( picLocation, width, height );
	}
}

const unsigned int CMainGrid::GetRowsCount()const
{
	return m_rowsCount;
}

const unsigned int CMainGrid::GetColumnsCount()const
{
	return m_columnsCount;
}

const std::string CMainGrid::GetSlabPictureLoc( const unsigned int column, const unsigned int row )const
{
	return GetSlabPictureLoc( row*column + column );
}

const std::string CMainGrid::GetSlabPictureLoc( const unsigned int slabIndex )const
{
	return m_slab[slabIndex].GetImgLoc();
}

const unsigned int CMainGrid::GetImgWidth( const unsigned int column, const unsigned int row )const
{
	return m_slab[row*column + column].GetImgWidth();
}

const unsigned int CMainGrid::GetImgHeight( const unsigned int column, const unsigned int row )const
{
	return m_slab[ row*column + column ].GetImgHeight();
}

const unsigned int CMainGrid::GetSlabPositionX( const unsigned int column, const unsigned int row )const
{
	return GetSlabPositionX( row*column + column );
}

const unsigned int CMainGrid::GetSlabPositionY( const unsigned int column, const unsigned int row )const
{
	return GetSlabPositionY( row*column + column );
}

const unsigned int CMainGrid::GetSlabPositionX( const unsigned int slabIndex )const
{
	return m_slab.at( slabIndex ).GetX();
}

const unsigned int CMainGrid::GetSlabPositionY( const unsigned int slabIndex )const
{
	return m_slab.at( slabIndex ).GetY();
}