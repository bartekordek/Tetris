#include "NodeCreator.h"
#include "NodeImageCreator.h"
#include "GeneralUtilities.h"

#include "ObjectNode.h"
#include "ScreenNode.h"

namespace MOGE
{
	ScreenNode NodeCreator::CreateScreen( const Size& size )
	{

	}
	//NodePtr& NodeFactory::CreateScreen( const Size& size )
	//{
	//	//Node* newNode = new Node( "MainScreen", Path( "" ), size );

	//	//ImagePtr imagePtr = NodeImageFactory::CreateScreen( size );
	//	//newNode->SetImage( imagePtr );

	//	//NodePtr& nodePtr = Create( newNode );
	//	//
	//	//return nodePtr;
	//	static NodePtr node;
	//	return node;
	//}

	//NodePtr& NodeFactory::CreateFromImage( const Path filePath, const Position position, const String& name )
	//{
	///*	Node* newNode = new Node( name, filePath, Size(), position );

	//	ImagePtr imagePtr = NodeImageFactory::CreateImage( filePath );
	//	newNode->SetImage( imagePtr );

	//	NodePtr& nodePtr = Create( newNode );
	//	
	//	return nodePtr;*/
	//	static NodePtr node;
	//	return node;
	//}

	//NodePtr& NodeFactory::CreateEmpty( const Position& position, const Size& size )
	//{
	//	//Node* newNode = new Node( "", "", size, position );
	//	//NodePtr& nodePtr = Create( newNode );
	//	//return nodePtr;
	//	static NodePtr node;
	//	return node;
	//}

	//NodePtr NodeFactory::GetNode( const Path& path )
	//{
	//	//for( auto& node : nodes )
	//	//{
	//	//	if( node->GetPath() == path )
	//	//	{
	//	//		return node;
	//	//	}
	//	//}
	//	return NodePtr();
	//}

	//NodePtr NodeFactory::GetNodeByName( const String& name )
	//{
	//	//for( const NodePtr& node : nodes )
	//	//{
	//	////	Node node;
	//	//	node->
	//	//	if( node->GetName() == name )
	//	//	{
	//	//		return node;
	//	//	}
	//	//}
	//	return NodePtr();
	//}

	//NodePtr& NodeFactory::Create( Node* nodeRawPtr )
	//{
	//	NodePtr* nodePtr = new NodePtr( nodeRawPtr );
	//	nodes.push_back( *nodePtr );
	//	return *nodePtr;
	//}

	//const bool NodeFactory::NodeExist( const String& nodeName )
	//{
	//	//for( const auto& node: nodes )
	//	//{
	//	//	if( node->GetName() == nodeName )
	//	//	{
	//	//		return true;
	//	//	}
	//	//}
	//	return false;
	//}

	//const bool NodeFactory::NodeExist( const NodePtr& node )
	//{
	//	for( const auto& currentNode : nodes )
	//	{
	//		if( currentNode.get() == node.get() )
	//		{
	//			return true;
	//		}
	//	}
	//	return false;
	//}

	//Vector<NodePtr> NodeFactory::nodes;
}