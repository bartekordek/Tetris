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
		createMatrixOfSize( rowsCount, columnsCount );
	}

	Matrix2D( const Matrix2D& matrix )
	{
		createMatrixOfSize( matrix.rowsCount, matrix.columnsCount );
		copy( matrix );
	}

	virtual ~Matrix2D()
	{
		release();
	}

	Matrix2D& operator=( const Matrix2D& matrix )
	{
		if( &matrix != this )
		{
			release();
			createMatrixOfSize( matrix.rowsCount, matrix.columnsCount );
			copy( matrix );
		}
		return *this;
	}

	Type& operator()( const unsigned rowIndex, const unsigned colIndex )
	{
		return this->getValue( rowIndex, colIndex );
	}

	Type& operator()( const unsigned int elementIndex )
	{
		const unsigned int colIndex = elementIndex % this->columnsCount;
		const unsigned int rowIndex = elementIndex / this->rowsCount;
		return this->getValue( rowIndex, colIndex );
	}

	void set( const unsigned rowIndex, const unsigned colIndex, const Type& value )
	{
		this->getValue( rowIndex, colIndex ) = value;
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
		if( true == isZero() )
		{
			return;
		}

		if( Directions::U == direction )
		{
			while( this->rowIsEmpty( 0 ) )
			{
				moveElements( direction );
			}
		}
		else if( Directions::D == direction )
		{
			while( this->rowIsEmpty( this->rowsCount - 1 ) )
			{
				moveElements( direction );
			}
		}
		else if( Directions::R == direction )
		{
			while( this->columnIsEmpty( this->columnsCount - 1 ) )
			{
				moveElements( direction );
			}
		}
		else if( Directions::L == direction )
		{
			while( this->columnIsEmpty( 0 ) )
			{
				moveElements( direction );
			}
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
				int columnIndex =
				Directions::R == direction ? this->columnsCount - 1: 0 ;
				Directions::R == direction ? columnIndex >= 0: columnIndex < static_cast<int> (this->columnsCount);
				Directions::R == direction ? --columnIndex: ++columnIndex )
			{
				const unsigned int targetColumnIndex = columnIndex - offset.second;
				if( elementExist( rowIndex + offset.first, targetColumnIndex ) )
				{
					this->values[rowIndex][columnIndex] = this->values[rowIndex + offset.first][targetColumnIndex];
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
	const bool columnIsEmpty( const unsigned int columnIndex )const
	{
		if( columnIndex >= this->columnsCount )
		{
			return false;
		}

		for( unsigned int i = 0; i < this->rowsCount; ++i )
		{
			if( this->values[i][columnIndex] != static_cast<Type>( 0 ) )
			{
				return false;
			}
		}
		return true;
	}

	const bool rowIsEmpty( const unsigned int rowIndex )const
	{
		if( rowIndex >= this->rowsCount )
		{
			return false;
		}

		for( unsigned int i = 0; i < this->columnsCount; ++i )
		{
			if( this->values[rowIndex][i] != static_cast<Type>( 0 ) )
			{
				return false;
			}
		}
		return true;
	}

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

	void createMatrixOfSize( const unsigned rowsCount, const unsigned columnsCount )
	{
		setRowsCount( rowsCount );
		setColumnsCount( columnsCount );
		allocateValues();
		applyValue( static_cast<Type>( 0 ) );
	}

	void setRowsCount( const unsigned int rowsCount )
	{
		this->rowsCount = rowsCount;
	}

	void setColumnsCount( const unsigned int columnsCount )
	{
		this->columnsCount = columnsCount;
	}

	void allocateValues()
	{
		this->values = new Type*[rowsCount];
		for( unsigned int rowIndex = 0; rowIndex < this->rowsCount; ++rowIndex )
		{
			this->values[rowIndex] = new Type[columnsCount];
		}
	}

	void applyValue( const Type& value )
	{
		for( unsigned int rowIndex = 0; rowIndex < this->rowsCount; ++rowIndex )
		{
			for( unsigned int columnIndex = 0; columnIndex < this->columnsCount; ++columnIndex )
			{
				this->values[rowIndex][columnIndex] = static_cast<Type>( 0 );
			}
		}
	}

	Type& getValue( const unsigned int rowIndex, const unsigned int columnIndex )
	{
		if( rowIndex >= this->rowsCount )
		{
			throw std::runtime_error( 
				"Row index " + 
				std::to_string( rowIndex ) + 
				" is bigger than rows count: " +
				std::to_string( this->rowsCount ) + "." );
		}

		if( columnIndex >= this->columnsCount )
		{
			throw std::runtime_error( 
				"Column index " + 
				std::to_string( columnIndex ) + 
				" is bigger than column count: " + 
				std::to_string( this->columnsCount ) + "." );
		}

		return values[rowIndex][columnIndex];
	}

	void release()
	{
		for( unsigned int i = 0; i < rowsCount; ++i )
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