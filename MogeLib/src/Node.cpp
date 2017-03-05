#include "Node.h"

namespace Moge
{
	Node::Node( const MyString& name ): Name( name )
	{
		if( GetName().empty() )
		{
			static unsigned int index = 0;
			SetName( MyString( ( "Node:" + std::to_string( index++ ) ).c_str() ) );
		}
	}

	Node::~Node()
	{
	}
}