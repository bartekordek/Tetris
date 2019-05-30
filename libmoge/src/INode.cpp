#include "INode.h"

using namespace Moge;

INode::INode( const CUL::MyString& name ): Name( name )
{
    if( GetName().empty() )
    {
        static unsigned int index = 0;
        setName( "Node:" + std::to_string( index++ ) );
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

CUL::CnstMyStr& INode::getName()const
{
    return this->m_name;
}

void INode::setName( CUL::CnstMyStr& name )
{
    this->m_name = name;
}