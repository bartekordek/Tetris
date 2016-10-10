#pragma once

#include <iostream>
#include <iomanip>

namespace Moge
{
namespace Math
{

enum class Directions: char
{
	L, R, U, D
};

inline std::pair<int,int> direction2RowCol( const Directions direction )
{
	if( Directions::U == direction )
	{
		return std::pair<int, int>( 1, 0 );
	}

	if( Directions::D == direction )
	{
		return std::pair<int, int>( -1, 0 );
	}

	if( Directions::R == direction )
	{
		return std::pair<int, int>( 0, 1 );
	}

	if( Directions::L == direction )
	{
		return std::pair<int, int>( 0, -1 );
	}

	return std::pair<int, int>( 0, 0 );
}

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
		const unsigned int colIndex = elementIndex % this->columnsCount;
		const unsigned int rowIndex = elementIndex / this->rowsCount;
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

	void moveElementsUntillNoEmptyLine( const Directions direction )
	{
		if( true )
		{
			
		}
	}

	void moveElements( const Directions direction )
	{
		std::pair<int, int> offset = direction2RowCol( direction );

		for( 
			int rowIndex =
			Directions::D == direction ? this->rowsCount - 1 : 0 ;
			Directions::D == direction ? rowIndex >= 0 : rowIndex < static_cast<int>( this->rowsCount );
			Directions::D == direction ? --rowIndex: ++rowIndex )
		{
			for( 
				unsigned int columnIndex =
				Directions::L == direction ? this->columnsCount: 0 ;
				Directions::L == direction ? columnIndex >= 0: columnIndex < this->columnsCount;
				Directions::L == direction ? --columnIndex: ++columnIndex )
			{
				if( elementExist( rowIndex + offset.first, columnIndex + offset.second ) )
				{
					this->values[rowIndex][columnIndex] = this->values[rowIndex + offset.first][columnIndex + offset.second];
				}
				else
				{
					this->values[rowIndex][columnIndex] = static_cast<Type>( 0 );
				}

			}
		}
	}

	const bool elementExist( const unsigned row, const unsigned col )const
	{
		if( this->rowsCount <= row || this->columnsCount <= col )
		{
			return false;
		}
		return true;
	}

	const bool isZero()const
	{
		auto zeroValue = static_cast<Type>( 0 );
		for( unsigned int i = 0; i < this->rowsCount; ++i )
		{
			for( unsigned int j = 0; j < this->rowsCount; ++j )
			{
				if( zeroValue !=  this->values[i][j] )
				{
					return false;
				}
			}
		}
		return true;
	}

	void print()const
	{
		for( unsigned int i = 0; i < this->rowsCount; ++i )
		{
			for( unsigned int j = 0; j < this->rowsCount; ++j )
			{
				std::cout << std::setw( 3 ) << this->values[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
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
		for( unsigned int rowIndex = 0; rowIndex < this->rowsCount; ++rowIndex )
		{
			for( unsigned int columnIndex = 0; columnIndex < this->columnsCount; ++columnIndex )
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
		applyValue( static_cast<Type>( 0 ) );
	}

	void applyValue( const Type& value )
	{
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