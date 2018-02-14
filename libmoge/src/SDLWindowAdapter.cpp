#include "SDLWindowAdapter.hpp"
#include "SDLTextureNode.hpp"
#include "CUL/ListVector.hpp"
using namespace Moge;

SDL2WindowAdapter::SDL2WindowAdapter():
    nodes( new CUL::ListVector<NodePtr>() )
{

}

SDL2WindowAdapter::~SDL2WindowAdapter()
{

}

void SDL2WindowAdapter::setSDLWin( SDL2W::IWindow* win )
{
    this->m_sdlWindow = win;
}

#if _MSC_VER
__pragma( warning( push ) ) \
__pragma( warning( disable:4100 ) )
#endif
INode* SDL2WindowAdapter::create(
    const CUL::FS::Path& filePath,
    const CUL::Math::Vector3Di& position,
    const CUL::MyString& name )
{
    auto obj = this->m_sdlWindow->createObject( filePath );
    auto textureNode = new SDLTextureNode();
    textureNode->setTexture( obj.get() );
    NodePtr nodePtr( textureNode );
    this->nodes->pushBack( nodePtr );
    return nodePtr.get();
}
#if _MSC_VER
__pragma( warning( pop ) )
#endif

void SDL2WindowAdapter::removeNode( const INode* node )
{
    auto& it = this->nodes->getRandomIterator();
    while( it.hasNext() )
    {
        if( it.next().get() == node )
        {
            nodes->remove( it );
            break;
        }
    }
}

const bool SDL2WindowAdapter::exist( const INode* node )const
{
    auto& it = this->nodes->getRandomIterator();
    while( it.hasNext() )
    {
        if( it.next().get() == node )
        {
            return true;
        }
    }
    return false;
}

const unsigned int SDL2WindowAdapter::count()const
{
    return static_cast<unsigned int>( this->nodes->size() );
}

void SDL2WindowAdapter::setBackgroundColor( const ColorE color )
{
    this->m_sdlWindow->setBackgroundColor( color );
}

void SDL2WindowAdapter::setBackgroundColor( const ColorS& color )
{
    this->m_sdlWindow->setBackgroundColor( color );
}