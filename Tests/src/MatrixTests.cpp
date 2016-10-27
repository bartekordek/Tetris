#include "MatrixTests.h"

using namespace Moge::Math;

TEST_F( MatrixTests, setTest )
{
	const int value2BeSet = 0;
	const unsigned size = 2;
	SquareMatrix2D<int> matrix( size );
	matrix.set( 0, 0, value2BeSet );
	matrix.set( 0, 1, value2BeSet );
	matrix.set( 1, 0, value2BeSet );
	matrix.set( 1, 1, value2BeSet );

	ASSERT_EQ( value2BeSet, matrix( 0, 0 ) );
	ASSERT_EQ( value2BeSet, matrix( 0, 1 ) );
	ASSERT_EQ( value2BeSet, matrix( 1, 0 ) );
	ASSERT_EQ( value2BeSet, matrix( 1, 1 ) );
}

TEST_F( MatrixTests, rotateTest )
{
	const unsigned size = 6;
	SquareMatrix2D<unsigned int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		matrix( i ) = i;
	}
	matrix.print();
	matrix.rotate();
	matrix.print();
	matrix.rotate( false );
	matrix.print();

	for( unsigned int i = 0; i < size*size; ++i )
	{
		ASSERT_EQ( matrix( i ), i );
	}
}

TEST_F( MatrixTests, moveTestUp )
{
	const unsigned size = 6;
	SquareMatrix2D<unsigned int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		matrix( i ) = i;
	}
	matrix.moveElements( Directions::U );
	matrix.print();

	for( unsigned int i = 0; i < size*size; ++i )
	{
		unsigned int expected = 0;
		if( i < size * size - size )
		{
			expected = ( i + size ) % ( size * size );
		}
		auto given = matrix( i );
		ASSERT_EQ( given, expected  );
	}
}

TEST_F( MatrixTests, moveTestDown )
{
	const unsigned size = 6;
	SquareMatrix2D<unsigned int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		matrix( i ) = i;
	}
	matrix.moveElements( Directions::D );
	matrix.print();

	for( unsigned int i = 0; i < size*size; ++i )
	{
		unsigned int expected = i - size;
		if( i < size )
		{
			expected = 0;
		}
		auto given = matrix( i );
		ASSERT_EQ( given, expected );
	}
}

TEST_F( MatrixTests, moveTestRight )
{
	const unsigned size = 2;
	SquareMatrix2D<unsigned int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		matrix( i ) = i;
	}
	matrix.moveElements( Directions::D );
	ASSERT_EQ( matrix( 0, 0 ), 0 );
	ASSERT_EQ( matrix( 0, 1 ), 0 );
	ASSERT_EQ( matrix( 1, 0 ), 0 );
	ASSERT_EQ( matrix( 1, 1 ), 1 );
}

TEST_F( MatrixTests, moveElementsUntillNoEmptyLineUpTest )
{
	const unsigned size = 3;
	SquareMatrix2D<unsigned int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		if( i < 3 )
		{
			matrix( i ) = 0;
		}
		else
		{
			matrix( i ) = i;
		}
	}
	matrix.print();
	matrix.moveElementsUntillNoEmptyLine( Directions::U );
	matrix.print();
	for( unsigned int i = 0; i < size*size; ++i )
	{
		auto matrixValue = matrix( i );
		if( i < size*2 )
		{
			auto expected = i + 3;
			ASSERT_EQ( matrixValue, expected );
		}
		else
		{
			auto expected = 0;
			ASSERT_EQ( matrixValue, expected );
		}
	}
}

TEST_F( MatrixTests, moveElementsUntillNoEmptyLineDownTest )
{
	const unsigned size = 3;
	SquareMatrix2D<unsigned int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		if( i < 2 * size )
		{
			matrix( i ) = i + 1;
		}
		else
		{
			matrix( i ) = 0;
		}
	}
	matrix.print();
	matrix.moveElementsUntillNoEmptyLine( Directions::D );
	matrix.print();
	for( unsigned int i = 0; i < size*size; ++i )
	{
		if( i < 3 )
		{
			ASSERT_EQ(  0, matrix( i ) );
		}
		else
		{
			ASSERT_EQ(  i - 2, matrix( i ) );
		}
		
	}
}

TEST_F( MatrixTests, moveElementsUntillNoEmptyLineRightTest )
{
	const unsigned size = 3;
	SquareMatrix2D<unsigned int> matrix( size );

	matrix( 0, 0 ) = 1;
	matrix( 1, 0 ) = 1;
	matrix( 2, 0 ) = 1;
	matrix.print();
	matrix.moveElementsUntillNoEmptyLine( Directions::R );
	matrix.print();
	ASSERT_EQ( 1, matrix( 0, 2 ) );
	ASSERT_EQ( 1, matrix( 1, 2 ) );
	ASSERT_EQ( 1, matrix( 2, 2 ) );

	ASSERT_EQ( 0, matrix( 0, 0 ) );
	ASSERT_EQ( 0, matrix( 0, 1 ) );

	ASSERT_EQ( 0, matrix( 1, 0 ) );
	ASSERT_EQ( 0, matrix( 1, 1 ) );

	ASSERT_EQ( 0, matrix( 2, 0 ) );
	ASSERT_EQ( 0, matrix( 2, 1 ) );
}