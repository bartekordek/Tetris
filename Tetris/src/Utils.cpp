#include "Utils.h"

CTableCoor::CTableCoor( CUInt row,
						CUInt column ): m_row( row ), m_column( column )
{

}

CTableCoor& CTableCoor::operator=( const CTableCoor& coor )
{
	if( this != &coor )
	{
		m_column = coor.m_column;
		m_row = coor.m_row;
	}
	return *this;
}

CUInt CTableCoor::Col()const
{
	return m_column;
}

CUInt CTableCoor::Row()const
{
	return m_row;
}

void CTableCoor::Row( CUInt row )
{
	m_row = row;
}

void CTableCoor::Col( CUInt col )
{
	m_column = col;
}

void CTableCoor::ChangePosition( CUInt row, CUInt col )
{
	m_row = row;
	m_column = col;
}