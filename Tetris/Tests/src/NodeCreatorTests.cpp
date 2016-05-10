#include "NodeCreatorTests.h"

#include "NodeCreator.h"

TEST_F( NodeCreatorTests, BmpLoadTest )
{
	std::shared_ptr<MOGE::ObjectNode> node = MOGE::NodeCreator::CreateFromImage( genericWindowsImagePath );
	ASSERT_NE( node.get(), nullptr );
	MOGE::NodeCreator::RemoveNode( node );
}

TEST_F( NodeCreatorTests, RemoveTest )
{
	std::shared_ptr<MOGE::ObjectNode> node = MOGE::NodeCreator::CreateFromImage( genericWindowsImagePath );
	auto nodePtr = node.get();
	ASSERT_NE( node.get(), nullptr );
	MOGE::NodeCreator::RemoveNode( node );
	ASSERT_EQ( node.get(), nullptr );
	std::shared_ptr<MOGE::ObjectNode> newNode(nodePtr);
	ASSERT_EQ( MOGE::NodeCreator::Exist( newNode ), false );
}

TEST_F( NodeCreatorTests, NodeAutoAutoAddTest )
{
	std::shared_ptr<MOGE::ObjectNode> node = MOGE::NodeCreator::CreateFromImage( genericWindowsImagePath );
	ASSERT_EQ( MOGE::NodeCreator::Exist( node ), true );
	MOGE::NodeCreator::RemoveNode( node );
}

MOGE::Path NodeCreatorTests::testBmpFile;
MOGE::Path NodeCreatorTests::genericWindowsImagePath;