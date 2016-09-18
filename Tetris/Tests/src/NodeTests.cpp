#include "NodeTests.h"
#include "ScreenNode.h"

TEST_F( NodeTests, CheckIfScreenIsNullptrAfterConstructorCall )
{
	MogeLib::ScreenNode screenNode;
	ASSERT_EQ( screenNode.GetScreen(), nullptr );
}

TEST_F( NodeTests, ScreenAfterCreationIsNotNull )
{
	MogeLib::ScreenNode screenNode;
	screenNode.Initialize();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
	screenNode.DestroyScreen();
}

TEST_F( NodeTests, DestroyScreen )
{
	MogeLib::ScreenNode screenNode;
	screenNode.Initialize();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
	screenNode.DestroyScreen();
	ASSERT_NE( screenNode.GetScreen(), nullptr );
}