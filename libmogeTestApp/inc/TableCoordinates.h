#pragma once

#include "BasicTypedefs.hpp"

#include <vector>

class MatrixPos
{
public:
    MatrixPos() = default;
    MatrixPos( const MatrixPos& tableCoord );
    MatrixPos( cunt row, cunt column );
    virtual ~MatrixPos() = default;

    MatrixPos& operator=( const MatrixPos& right );
    MatrixPos operator+( const MatrixPos& right )const;
    MatrixPos operator-( const MatrixPos& right )const;

    cunt getRow()const;
    cunt getCol()const;
    const double getX()const;
    const double getY()const;
    void setRow( cunt row );
    void setCol( cunt col );
    void changePosition( cunt row, cunt col );

    static void setXOffsets( const double xoff );
    static void setYOffsets( const double yoff );

private:
    void matrix2Coords();

    static double s_xOff;
    static double s_yOff;
    static double s_yOff;
    static double s_yOff;

    unsigned row = 0;
    unsigned column = 0;
    double m_x = 0.0;
    double m_y = 0.0;
};

typedef std::vector<MatrixPos> CoordinatestList;