#pragma once

#include "Matrix2D.hpp"

namespace Moge
{
namespace Math
{
template <typename Type>
class SquareMatrix2D: public Matrix2D<Type>
{
public:
	SquareMatrix2D()
	{
	}

	explicit SquareMatrix2D( const unsigned size ): Matrix2D<Type>( size, size )
	{
	}

	virtual ~SquareMatrix2D()
	{
	}

	void rotate( const bool clockWise = true )
	{
		std::vector< std::vector<Type> > copiedValues = Matrix2D<Type>::copyValues();
		const unsigned int size = Matrix2D<Type>::getRowsCount();
		for( unsigned int rowIndex = 0; rowIndex < size; ++rowIndex )
		{
			for( unsigned int columnIndex = 0; columnIndex < size; ++columnIndex )
			{
				if( clockWise )
				{
					Matrix2D<Type>::operator()( rowIndex, columnIndex ) = copiedValues[size - columnIndex - 1][rowIndex];
				}
				else
				{
					Matrix2D<Type>::operator()( rowIndex, columnIndex ) = copiedValues[columnIndex][size - rowIndex - 1];
				}
			}
		}
	}

	const unsigned int getSize()const
	{
		return Matrix2D<Type>::getColumnCount();
	}

	const Type& det()const
	{
		return static_cast<Type>( 0 );//TODO
	}

protected:
private:
};

}
}