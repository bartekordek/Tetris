#include "SDLWindowAdapter.hpp"
#include "SDLSprite.hpp"
using namespace Moge;

SDL2WindowAdapter::SDL2WindowAdapter()
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
    auto textureNode = new SDLSprite();
    textureNode->setTexture( obj );
    NodePtr nodePtr( textureNode );
    this->nodes[ textureNode ] = nodePtr;
    return nodePtr.get();
}
#if _MSC_VER
__pragma( warning( pop ) )
#endif

void SDL2WindowAdapter::removeNode( INode* node )
{
    auto it = this->nodes.find( node );
    this->nodes.erase( it );
}

const bool SDL2WindowAdapter::exist( const INode* node )const
{
    auto it = this->nodes.find( const_cast<INode*>( node ) );
    if ( this->nodes.end() == it )
    {
        return false;
    }
    return true;
}

const unsigned int SDL2WindowAdapter::count()const
{
    return static_cast<unsigned int>( this->nodes.size() );
}

void SDL2WindowAdapter::setBackgroundColor( const ColorE color )
{
    this->m_sdlWindow->setBackgroundColor( color );
}

void SDL2WindowAdapter::setBackgroundColor( const ColorS& color )
{
    this->m_sdlWindow->setBackgroundColor( color );
}