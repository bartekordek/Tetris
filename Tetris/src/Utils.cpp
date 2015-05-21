#include "Utils.h"

CTableCoor::CTableCoor( const unsigned row, 
						const unsigned column ): m_row( row ), m_column( column )
{

}

const unsigned CTableCoor::GetCol()const
{
	return m_column;
}

const unsigned CTableCoor::GetRow()const
{
	return m_row;
}