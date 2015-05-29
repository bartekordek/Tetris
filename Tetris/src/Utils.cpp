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

CUInt CTableCoor::GetCol()const
{
	return m_column;
}

CUInt CTableCoor::GetRow()const
{
	return m_row;
}