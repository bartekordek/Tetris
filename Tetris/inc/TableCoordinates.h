#pragma once

#include <vector>

class MatrixPos
{
public:
	MatrixPos() = default;
	MatrixPos( const MatrixPos& tableCoord );
	MatrixPos( const unsigned int row, const unsigned int column );
	virtual ~MatrixPos() = default;

	MatrixPos& operator=( const MatrixPos& right );
	MatrixPos operator+( const MatrixPos& right )const;
	MatrixPos operator-( const MatrixPos& right )const;

    const unsigned int getRow()const;
    const unsigned int getCol()const;
	void setRow( const unsigned int row );
	void setCol( const unsigned int col );
	void changePosition( const unsigned int row, const unsigned int col );

private:
	unsigned row = 0;
	unsigned column = 0;
};

typedef std::vector<MatrixPos> CoordinatestList;