#include "ObjectNodeTests.h"
#include "ObjectNode.h"

TEST_F( ObjectNodeTests, CheckIfIsNullptrAfterConstructorCall )
{
	MogeLib::ObjectNodeContent objectNode;
	ASSERT_EQ( objectNode.GetSurface(), nullptr );
}

TEST_F( ObjectNodeTests, LoadWorks )
{
	
}