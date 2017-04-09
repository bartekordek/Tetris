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
	std::unique_ptr<Moge::IList<double>> result( Moge::ListFactory<double>::createLinkedListPtr() );
	result->pushBack( 2.2 );
	GTEST_ASSERT_EQ( 1, result->size() );
}

TEST_F( ListTests, VectorIntIterate )
{
	std::unique_ptr<Moge::IList<unsigned>> result( Moge::ListFactory<unsigned>::createLinkedListPtr() );
	unsigned limit = 1000 * 1000;
	for( unsigned i = 0; i < limit; ++i )
	{
		result->pushBack( i );
	}
	
	unsigned i = 0;
	Moge::IIterator<unsigned>& iterator = result->getRandomIterator();
	iterator = result->begin();
	GTEST_ASSERT_EQ( true, iterator.hasNext() );
	while( iterator.hasNext() )
	{
		GTEST_ASSERT_EQ( i, iterator++ );
		++i;
	}
}