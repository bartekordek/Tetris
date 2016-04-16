#include "NodeTests.h"
#include "ScreenNode.h"

TEST_F( NodeTests, CheckIfScreenIsNullptrAfterConstructorCall )
{
	MOGE::ScreeNode screenNode;
	ASSERT_EQ( screenNode.GetScreen(), nullptr );
}

TEST_F( NodeTests, ScreenAfterCreationIsNotNull )
{
	MOGE::ScreeNode screenNode;
	screenNode.CreateScreen();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
}
