#include "TableCoordinates.h"

double MatrixPos::s_xOff = 0.0;
double MatrixPos::s_yOff = 0.0;

MatrixPos::MatrixPos( const MatrixPos& tableCoord ):
    row( tableCoord.row ),
    column( tableCoord.column ),
    m_x( s_xOff ),
    m_y( s_yOff )
{
}

MatrixPos::MatrixPos( cunt  row, cunt  column ):
    row( row ),
    column( column )
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

cunt MatrixPos::getCol()const
{
    return this->column;
}

cunt MatrixPos::getRow()const
{
    return this->row;
}

void MatrixPos::setRow( cunt  row )
{
    this->row = row;
}

void MatrixPos::setCol( cunt  col )
{
    this->column = col;
}

void MatrixPos::changePosition( cunt  row, cunt  col )
{
    this->row = row;
    this->column = col;
}

void MatrixPos::matrix2Coords()
{
    this->m_x = s_xOff + column *
}

void MatrixPos::setXOffsets( const double xoff )
{
    s_xOff = xoff;
}

void MatrixPos::setYOffsets( const double yoff )
{
    s_yOff = yoff;
}