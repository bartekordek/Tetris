#include "TableCoordinates.h"

MatrixPos::MatrixPos( const MatrixPos& tableCoord ):row( tableCoord.row ), column( tableCoord.column )
{
}

MatrixPos::MatrixPos( const unsigned int row, const unsigned int column ): row( row ), column( column )
{
}

MatrixPos& MatrixPos::operator=( const MatrixPos& coor )
{
    if( this != &coor )
    {
        this->column = coor.column;
        this->row = coor.row;
    }
    return *this;
}

MatrixPos MatrixPos::operator+( const MatrixPos& right ) const
{
    MatrixPos result( this->row + right.row, this->column + right.column );
    return result;
}

MatrixPos MatrixPos::operator-( const MatrixPos& right ) const
{
    MatrixPos result( this->row - right.row, this->column - right.column );
    return result;
}

const unsigned int MatrixPos::getCol()const
{
    return this->column;
}

const unsigned int MatrixPos::getRow()const
{
    return this->row;
}

void MatrixPos::setRow( const unsigned int row )
{
    this->row = row;
}

void MatrixPos::setCol( const unsigned int col )
{
    this->column = col;
}

void MatrixPos::changePosition( const unsigned int row, const unsigned int col )
{
    this->row = row;
    this->column = col;
}