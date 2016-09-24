#include "NodeCreatorTests.h"

#include "NodeCreator.h"

TEST_F( NodeCreatorTests, BmpLoadTest )
{
	std::shared_ptr<MogeLib::ObjectNodeContent> node = MogeLib::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
	MogeLib::NodeCreator::RemoveNode( node );
}

TEST_F( NodeCreatorTests, RemoveTest )
{
	auto nodesCountBeforeAddingNewNode = MogeLib::NodeCreator::Count();
	std::shared_ptr<MogeLib::ObjectNodeContent> node = MogeLib::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
	MogeLib::NodeCreator::RemoveNode( node );
	ASSERT_EQ( MogeLib::NodeCreator::Count(), nodesCountBeforeAddingNewNode );
}

TEST_F( NodeCreatorTests, NodeAutoAutoAddTest )
{
	std::shared_ptr<MogeLib::ObjectNodeContent> node = MogeLib::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_EQ( MogeLib::NodeCreator::Exist( node ), true );
	MogeLib::NodeCreator::RemoveNode( node );
}

MogeLib::Path NodeCreatorTests::testBmpFile;
