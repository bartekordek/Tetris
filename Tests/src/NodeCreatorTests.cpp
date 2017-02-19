#include "NodeCreatorTests.h"
#include "MogeLibMain.h"

using EM = Moge::EngineManager;

TEST_F( NodeCreatorTests, BmpLoadTest )
{
	auto node = EM::getEngine()->getNodeFactory()->CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
    EM::getEngine()->getNodeFactory()->removeNode( node );
}

TEST_F( NodeCreatorTests, RemoveTest )
{
	auto nodesCountBeforeAddingNewNode = EM::getEngine()->getNodeFactory()->Count();
	auto node = EM::getEngine()->getNodeFactory()->CreateFromImage( testBmpFile );
	ASSERT_NE( node.get(), nullptr );
    EM::getEngine()->getNodeFactory()->removeNode( node );
	ASSERT_EQ( EM::getEngine()->getNodeFactory()->Count(), nodesCountBeforeAddingNewNode );
}

TEST_F( NodeCreatorTests, NodeAutoAutoAddTest )
{
	auto node = EM::getEngine()->getNodeFactory()->CreateFromImage( testBmpFile );
	ASSERT_EQ( EM::getEngine()->getNodeFactory()->exist( node ), true );
	EM::getEngine()->getNodeFactory()->removeNode( node );
}

Moge::Path NodeCreatorTests::testBmpFile;
