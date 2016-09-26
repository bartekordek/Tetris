#include "NodeTests.h"
#include "ScreenNode.h"

TEST_F( NodeTests, CheckIfScreenIsNullptrAfterConstructorCall )
{
	Moge::ScreenNode screenNode;
	ASSERT_EQ( screenNode.GetScreen(), nullptr );
}

TEST_F( NodeTests, ScreenAfterCreationIsNotNull )
{
	Moge::ScreenNode screenNode;
	screenNode.initialize();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
	screenNode.DestroyScreen();
}

TEST_F( NodeTests, DestroyScreen )
{
	Moge::ScreenNode screenNode;
	screenNode.initialize();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
	screenNode.DestroyScreen();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
}