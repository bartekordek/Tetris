#include "INode.h"

using namespace Moge;

INode::INode( const CUL::MyString& name ): Name( name )
{
    if( GetName().empty() )
    {
        static unsigned int index = 0;
        setName( CUL::MyString( ( "Node:" + std::to_string( index++ ) ).c_str() ) );
    }
}

INode::~INode()
{
}
#if _MSC_VER
__pragma( warning( push ) ) \
__pragma( warning( disable:4100 ) )
#endif
void INode::attach( INode* node )
{
    // TODO
}
#if _MSC_VER
__pragma( warning( pop ) )
#endif

const std::string& INode::getName()const
{
    return this->m_name;
}

void INode::setName( const std::string& name )
{
    this->m_name = name;
}