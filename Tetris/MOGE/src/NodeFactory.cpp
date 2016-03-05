#include "NodeFactory.h"
#include "NodeImageFactory.h"

namespace MOGE
{
	NodePtr& NodeFactory::CreateScreen( const Size& size )
	{
		//Node* newNode = new Node( "", Path( "" ), size );
		//newNode->SetName( "MainScreen" );

		//ImagePtr imagePtr = NodeImageFactory::CreateScreen( size );
		//newNode->SetImage( imagePtr );

		//NodePtr& nodePtr = CreateEmpty( newNode );
		//
		//return nodePtr;
		return NodePtr();
	}

	NodePtr& NodeFactory::CreateFromImage( Path filePath, Position position, const String& name )
	{
		//Node* newNode = new Node( "", Path(""), Size(), position );
		//if( name.empty() )
		//{
		//	newNode->SetName( filePath.string() );
		//}
		//else
		//{
		//	newNode->SetName( name );
		//}

		//ImagePtr imagePtr = NodeImageFactory::CreateImage( filePath );
		//newNode->SetImage( imagePtr );

		//NodePtr& nodePtr = CreateEmpty( newNode );
		//
		//return nodePtr;
		return NodePtr();
	}

	NodePtr& NodeFactory::CreateEmpty( const Position& position, const Size& size )
	{
		//Node* newNode = new Node( "", "", size, position );
		//NodePtr& nodePtr = CreateEmpty( newNode );
		//return nodePtr;
		return NodePtr();
	}

	//NodePtr& NodeFactory::CopyNode( const NodePtr& node )
	//{
	//	NodePtr& 
	//}

	NodePtr NodeFactory::GetNode( const Path& path )
	{
		//for( auto& node : nodes )
		//{
		//	if( node->GetPath() == path )
		//	{
		//		return node;
		//	}
		//}
		//return NodePtr();
		return NodePtr();
	}

	NodePtr& NodeFactory::CreateEmpty( Node* nodeRawPtr )
	{
		//NodePtr* nodePtr = new NodePtr( nodeRawPtr );
		//nodes.push_back( *nodePtr );
		//return *nodePtr;
		return NodePtr();
	}

	const bool NodeFactory::NodeExist( const String& nodeName )
	{
		//for( const auto& node: nodes )
		//{
		//	if( node->GetName() == nodeName )
		//	{
		//		return true;
		//	}
		//}
		//return false;
		return true;
	}

	const bool NodeFactory::NodeExist( const NodePtr& node )
	{
		//for( const auto& currentNode : nodes )
		//{
		//	if( currentNode.get() == node.get() )
		//	{
		//		return true;
		//	}
		//}
		//return false;
		return true;
	}

//	Vector<NodePtr> NodeFactory::nodes;
}