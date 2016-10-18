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

	ASSERT_EQ( value2BeSet, matrix.get( 0, 0 ) );
	ASSERT_EQ( value2BeSet, matrix.get( 0, 1 ) );
	ASSERT_EQ( value2BeSet, matrix.get( 1, 0 ) );
	ASSERT_EQ( value2BeSet, matrix.get( 1, 1 ) );
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