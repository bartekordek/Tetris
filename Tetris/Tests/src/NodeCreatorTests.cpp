#include "NodeCreatorTests.h"
#include "NodeCreator.h"

TEST_F( NodeCreatorTests, BmpLoadTest )
{
	std::shared_ptr<Moge::ObjectNodeContent> node = Moge::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
	Moge::NodeCreator::RemoveNode( node );
}

TEST_F( NodeCreatorTests, RemoveTest )
{
	auto nodesCountBeforeAddingNewNode = Moge::NodeCreator::Count();
	
	std::shared_ptr<Moge::ObjectNodeContent> node = Moge::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
	Moge::NodeCreator::RemoveNode( node );
	ASSERT_EQ( Moge::NodeCreator::Count(), nodesCountBeforeAddingNewNode );
}

TEST_F( NodeCreatorTests, NodeAutoAutoAddTest )
{
	std::shared_ptr<Moge::ObjectNodeContent> node = Moge::NodeCreator::CreateFromImage( testBmpFile );
	ASSERT_EQ( Moge::NodeCreator::Exist( node ), true );
	Moge::NodeCreator::RemoveNode( node );
}

Moge::Path NodeCreatorTests::testBmpFile;
