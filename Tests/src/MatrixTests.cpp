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
	const unsigned size = 2;
	SquareMatrix2D<int> matrix( size );
	for( unsigned int i = 0; i < size*size; ++i )
	{
		matrix( i ) = i;
	}
	matrix.print();
	matrix.rotate();
	matrix.print();

}