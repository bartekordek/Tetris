#pragma once

#include <iostream>

namespace Moge
{
namespace Math
{
template <typename Type>
class Matrix2D
{
public:
	Matrix2D()
	{
	}

	Matrix2D( const unsigned rowsCount, const unsigned columnsCount ): rowsCount( rowsCount ), columnsCount( columnsCount )
	{
		setSize( rowsCount, columnsCount );
	}

	Matrix2D( const Matrix2D& matrix )
	{
		setSize( matrix.rowsCount, matrix.columnsCount );
		copy( matrix );
	}

	virtual ~Matrix2D()
	{
		clear();
	}

	Matrix2D& operator=( const Matrix2D& matrix )
	{
		if( &matrix != this )
		{
			clear();
			setSize( matrix.rowsCount, matrix.columnsCount );
			copy( matrix );
		}
		return *this;
	}

	Type& operator()( const unsigned rowIndex, const unsigned colIndex )const
	{
		return this->values[rowIndex][colIndex];
	}

	Type& operator()( const unsigned int elementIndex )const
	{
		const unsigned int rowIndex = elementIndex % this->columnsCount;
		const unsigned int colIndex = elementIndex / this->rowsCount;
		return this->values[rowIndex][colIndex];
	}

	const Type& get( const unsigned rowIndex, const unsigned colIndex )const
	{
		return this->values[rowIndex][colIndex];
	}

	void set( const unsigned rowIndex, const unsigned colIndex, const Type& value )
	{
		this->values[rowIndex][colIndex] = value;
	}

	const unsigned int getColumnCount()const
	{
		return this->columnsCount;
	}

	const unsigned int getRowsCount()const
	{
		return this->rowsCount;
	}

	void print()const
	{
		for( unsigned int i = 0; i < this->rowsCount; ++i )
		{
			for( unsigned int j = 0; j < this->rowsCount; ++j )
			{
				std::cout << this->values[i][j];
			}
			std::cout << std::endl;
		}
	}

protected:
	Type** copyValues()const
	{
		Type** result = new Type*[rowsCount];
		for( unsigned int rowIndex = 0; rowIndex < this->rowsCount; ++rowIndex )
		{
			result[rowIndex] = new Type[columnsCount];
			for( unsigned int columnIndex = 0; columnIndex < this->columnsCount; ++columnIndex )
			{
				result[rowIndex][columnIndex] = static_cast<Type>( this->values[ rowIndex ][ columnIndex ] );
			}
		}
		return result;
	}

private:
	void copy( const Matrix2D& matrix )
	{
		for( auto rowIndex = 0; rowIndex < this->rowsCount; ++rowIndex )
		{
			for( auto columnIndex = 0; columnIndex < this->columnsCount; ++columnIndex )
			{
				this->values[rowIndex][columnIndex] = matrix.values[rowIndex][columnIndex];
			}
		}
	}

	void setSize( const unsigned rowsCount, const unsigned columnsCount )
	{
		this->rowsCount = rowsCount;
		this->columnsCount = columnsCount;
		values = new Type*[rowsCount];
		for( unsigned int rowIndex = 0; rowIndex < this->rowsCount; ++rowIndex )
		{
			this->values[rowIndex] = new Type[columnsCount];
			for( unsigned int columnIndex = 0; columnIndex < this->columnsCount; ++columnIndex )
			{
				this->values[rowIndex][columnIndex] = static_cast<Type>( 0 );
			}
		}
	}

	void clear()
	{
		for( unsigned int i = 0; i < rowsCount; ++ i )
		{
			delete[] this->values[i];
		}

		delete[] this->values;
		this->values = nullptr;
	}

	Type** values = nullptr;
	unsigned int rowsCount = 0;
	unsigned int columnsCount = 0;
};
}
}