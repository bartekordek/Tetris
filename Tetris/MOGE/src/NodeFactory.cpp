#include "NodeFactory.h"
#include "NodeImageFactory.h"

namespace MOGE
{
	NodePtr NodeFactory::CreateScreen( const Size& size )
	{
		Node* newNode = new Node( Path( "MainScreen" ), size );

		NodePtr nodePtr = std::make_shared<Node>( *newNode );
		ImagePtr imagePtr = NodeImageFactory::CreateScreen( size );
		nodePtr->SetImage( imagePtr );
		return nodePtr;
	}

	NodePtr NodeFactory::CreateFromImage( Path filePath, Position position )
	{
		Node* newNode = new Node( Size(), position );
		NodePtr nodePtr = std::make_shared<Node>( *newNode );
		ImagePtr imagePtr = NodeImageFactory::CreateImage( filePath );
		nodePtr->SetImage( imagePtr );
		return nodePtr;
	}
}