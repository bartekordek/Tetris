#include "ListTests.h"
#include "ListFactory.h"
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

TEST_F( ListTests, VectorAddDouble )
{
	std::unique_ptr<double> result( Moge::ListFactory<double>::createVectorListPtr()) );
	result->pushBack( 0.0 );
}
