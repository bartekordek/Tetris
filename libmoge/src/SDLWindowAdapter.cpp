#include "SDLWindowAdapter.hpp"
#include "SDLSprite.hpp"
#include "SDLTexture.hpp"

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

INode* SDL2WindowAdapter::createNode(
    const CUL::FS::Path& filePath,
    const CUL::Math::Vector3Di& position,
    const CUL::MyString& name )
{
    /*
    auto obj = this->m_sdlWindow->createObject( filePath );
    auto textureNode = new SDLSprite();
    textureNode->setTexture( obj );
    NodePtr nodePtr( textureNode );
    this->nodes[ textureNode ] = nodePtr;
    return nodePtr.get();
    */
}

INode* SDL2WindowAdapter::createNode(
    const ITexture* tex,
    const Vector3Di& position = Vector3Di( 0, 0, 0 ),
    const CUL::MyString& name = CUL::MyString( "" ) )
{
    INode* result = nullptr;
    return result;
}

ITexture* SDL2WindowAdapter::createTexture( const Path& path )
{
    ITexture* result = nullptr;
    auto it = this->m_textures.find( path.getPath().c_str() );
    if( this->m_textures.end() == it )
    {
        auto sdlTex = this->m_sdlWindow->createTexture( path );
        auto sdlTexWrap = new SDLTexture();
        sdlTexWrap->setTexture( sdlTex );
        TexPtr sdlTexPtr( sdlTexWrap );
        this->m_textures[ path.getPath().c_str() ] = sdlTexPtr;
    }
    else
    {
        result = it->second.get();
    }
    return result;
}

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