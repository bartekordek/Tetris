#include "NodeCreatorTests.h"

#include "NodeCreator.h"

TEST_F( NodeCreatorTests, BmpLoadTest )
{
	std::shared_ptr<MOGE::ObjectNodeContent> node = MOGE::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
	MOGE::NodeCreator::RemoveNode( node );
}

TEST_F( NodeCreatorTests, RemoveTest )
{
	auto nodesCountBeforeAddingNewNode = MOGE::NodeCreator::Count();
	std::shared_ptr<MOGE::ObjectNodeContent> node = MOGE::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
	MOGE::NodeCreator::RemoveNode( node );
	ASSERT_EQ( MOGE::NodeCreator::Count(), nodesCountBeforeAddingNewNode );
}

TEST_F( NodeCreatorTests, NodeAutoAutoAddTest )
{
	std::shared_ptr<MOGE::ObjectNodeContent> node = MOGE::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_EQ( MOGE::NodeCreator::Exist( node ), true );
	MOGE::NodeCreator::RemoveNode( node );
}

MOGE::Path NodeCreatorTests::testBmpFile;