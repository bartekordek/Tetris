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

	SquareMatrix2D( const unsigned size ): Matrix2D<Type>( size, size )
	{
	}

	virtual ~SquareMatrix2D()
	{
	}

	void rotate( const bool clockWise = true )
	{
		Type** copiedValues = Matrix2D<Type>::copyValues();
		const unsigned int size = Matrix2D<Type>::getRowsCount();
		for( unsigned int i = 0; i < size; ++i )
		{
			for( unsigned int j = 0; j < size; ++j )
			{
				Matrix2D<Type>::operator()( i, j ) = copiedValues[size - j][i];
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