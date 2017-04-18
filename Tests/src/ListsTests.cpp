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

TEST_F( ListTests, VectorIntIterateOneElement )
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
		GTEST_ASSERT_EQ( i, iterator.next() );
		++i;
	}
}

TEST_F( ListTests, VectorIntIterateTwoElements )
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
 		GTEST_ASSERT_EQ( i, iterator.next() );
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
		GTEST_ASSERT_EQ( i, iterator.next() );
		++i;
	}
}

TEST_F( ListTests, LinkedDoubleAdd )
{
	std::unique_ptr<Moge::IList<double>> result( Moge::ListFactory<double>::createLinkedListPtr() );
	result->pushBack( 2.2 );
	GTEST_ASSERT_EQ( 1, result->size() );
}

TEST_F( ListTests, LinkedIntIterateOneElement )
{
	std::unique_ptr<Moge::IList<unsigned>> result( Moge::ListFactory<unsigned>::createLinkedListPtr() );
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
		GTEST_ASSERT_EQ( i, iterator.next() );
		++i;
	}
}

TEST_F( ListTests, LinkedIntIterateTwoElements )
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
		GTEST_ASSERT_EQ( i, iterator.next() );
		++i;
	}
}

TEST_F( ListTests, LinkedIntIterateManyElements )
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
		GTEST_ASSERT_EQ( i, iterator.next() );
		++i;
	}
}