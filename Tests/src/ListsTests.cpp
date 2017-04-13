#include "ListTests.h"
#include "ListFactory.h"
#include "IIterator.h"
#include <memory>

ListTests::ListTests( void )
{
}

ListTests::~ListTests()
{
}

void ListTests::SetUpTestCase()
{   
}

void ListTests::TearDownTestCase()
{
}

TEST_F( ListTests, VectorDoubleAdd )
{
	std::unique_ptr<Moge::IList<double>> result( Moge::ListFactory<double>::createVectorListPtr() );
	result->pushBack( 2.2 );
	GTEST_ASSERT_EQ( 1, result->size() );
}

TEST_F( ListTests, VectorIntIterateManyOneElement )
{
	std::unique_ptr<Moge::IList<unsigned>> result( Moge::ListFactory<unsigned>::createVectorListPtr() );
	unsigned limit = 1;
	for( unsigned i = 0; i < limit; ++i )
	{
		result->pushBack( i );
	}

	unsigned i = 0;
	Moge::IIterator<unsigned>& iterator = result->getRandomIterator();
	GTEST_ASSERT_EQ( true, iterator.hasNext() );
	while( iterator.hasNext() )
	{
		auto value = iterator.next();
		std::cout << "i = " << i << ", val = " << value << "\n";
		GTEST_ASSERT_EQ( i, value );
		++i;
	}
}

TEST_F( ListTests, VectorIntIterateManyTwoElements )
{
	std::unique_ptr<Moge::IList<unsigned>> result( Moge::ListFactory<unsigned>::createVectorListPtr() );
	unsigned limit = 4;
	for( unsigned i = 0; i < limit; ++i )
	{
		result->pushBack( i );
	}

	unsigned i = 0;
	Moge::IIterator<unsigned>& iterator = result->getRandomIterator();
	GTEST_ASSERT_EQ( true, iterator.hasNext() );
	while( iterator.hasNext() )
	{
		auto value = iterator.next();
		std::cout << "i = " << i << ", val = " << value << "\n";
 		GTEST_ASSERT_EQ( i, value );
		++i;
	}
}

TEST_F( ListTests, VectorIntIterateManyElements )
{
	std::unique_ptr<Moge::IList<unsigned>> result( Moge::ListFactory<unsigned>::createVectorListPtr() );
	unsigned limit = 1000 * 1000;
	for( unsigned i = 0; i < limit; ++i )
	{
		result->pushBack( i );
	}
	
	unsigned i = 0;
	Moge::IIterator<unsigned>& iterator = result->getRandomIterator();
	GTEST_ASSERT_EQ( true, iterator.hasNext() );
	while( iterator.hasNext() )
	{
		auto value = iterator.getVal();
		GTEST_ASSERT_EQ( i, value );
		++iterator;
		++i;
	}
}