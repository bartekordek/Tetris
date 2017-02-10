#include "TableCoordinates.h"

CTableCoor::CTableCoor( const CTableCoor& tableCoord ):row( tableCoord.row ), column( tableCoord.column )
{
}

CTableCoor::CTableCoor( const unsigned int row, const unsigned int column ): row( row ), column( column )
{
}

CTableCoor& CTableCoor::operator=( const CTableCoor& coor )
{
	if( this != &coor )
	{
		this->column = coor.column;
		this->row = coor.row;
	}
	return *this;
}

CTableCoor CTableCoor::operator+( const CTableCoor& right ) const
{
	CTableCoor result( this->row + right.row, this->column + right.column );
	return result;
}

CTableCoor CTableCoor::operator-( const CTableCoor& right ) const
{
	CTableCoor result( this->row - right.row, this->column - right.column );
	return result;
}

const unsigned int CTableCoor::getCol()const
{
	return this->column;
}

const unsigned int CTableCoor::getRow()const
{
	return this->row;
}

void CTableCoor::setRow( const unsigned int row )
{
	this->row = row;
}

void CTableCoor::setCol( const unsigned int col )
{
	this->column = col;
}

void CTableCoor::changePosition( const unsigned int row, const unsigned int col )
{
	this->row = row;
	this->column = col;
}