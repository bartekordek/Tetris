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

//void CMainGrid::Draw()
//{
//	BOOST_FOREACH( CSlab slab, m_slab )
//	{
//		slab.Draw();
//	}
//}

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
			CSlab slab( j + initialX, i + initialY );
			m_slab.push_back( slab );
		}
	}
}

void CMainGrid::SetBackgroundPicture( const boost::filesystem::path& picLocation, const unsigned int width, const unsigned int height )
{
	BOOST_FOREACH( CSlab slab, m_slab )
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

const std::string& CMainGrid::GetSlabPictureLoc( const unsigned int column, const unsigned int row )const
{
	return m_slab.at( row*column + column ).GetImgLoc();
}