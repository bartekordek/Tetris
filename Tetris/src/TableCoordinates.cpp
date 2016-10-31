#include "TableCoordinates.h"

CTableCoor::CTableCoor( const CTableCoor& tableCoord ):row( tableCoord.row ), column( tableCoord.column )
{
}

CTableCoor::CTableCoor( CUInt row, CUInt column ): row( row ), column( column )
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

CTableCoor::~CTableCoor()
{
}

CUInt CTableCoor::Col()const
{
	return this->column;
}

CUInt CTableCoor::Row()const
{
	return this->row;
}

void CTableCoor::Row( CUInt row )
{
	this->row = row;
}

void CTableCoor::Col( CUInt col )
{
	this->column = col;
}

void CTableCoor::ChangePosition( CUInt row, CUInt col )
{
	this->row = row;
	this->column = col;
}