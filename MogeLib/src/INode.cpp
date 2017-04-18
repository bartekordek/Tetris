#include "INode.h"

namespace Moge
{
	INode::INode( const MyString& name ): Name( name )
	{
		if( GetName().empty() )
		{
			static unsigned int index = 0;
			SetName( MyString( ( "Node:" + std::to_string( index++ ) ).c_str() ) );
		}
	}

	INode::~INode()
	{
	}
}