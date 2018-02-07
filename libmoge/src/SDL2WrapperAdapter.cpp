#include "SDL2WrapperAdapter.hpp"
#include "SDLWindowAdapter.hpp"
#include "IKeyConcrete.hpp"

using namespace Moge;

SDL2WrapperAdapter::SDL2WrapperAdapter():
    m_sdlW( SDL2W::getSDL2Wrapper() )
{
}

SDL2WrapperAdapter::~SDL2WrapperAdapter()
{
    SDL2W::destroySDL2Wrapper();
}

#if _MSC_VER
__pragma(warning( push )) \
__pragma(warning( disable:4100 ))
#endif
IWindow* SDL2WrapperAdapter::createWindow(
    Vector3Du& size,
    Vector3Di& position,
    const std::string& winName )
{
    auto sdlWin = this->m_sdlW->createWindow(
        position,
        size,
        winName );
    auto sdlWinWrap = new SDL2WindowAdapter();
    sdlWinWrap->setSDLWin( sdlWin );
    return sdlWinWrap;
}

void SDL2WrapperAdapter::forceDestroy()
{
    SDL2W::destroySDL2Wrapper();
}

void SDL2WrapperAdapter::updateScreen()
{

}

void SDL2WrapperAdapter::clear()
{

}

#if _MSC_VER
__pragma( warning( pop ) )
#endif

void SDL2WrapperAdapter::runMainLoop()
{

}

void SDL2WrapperAdapter::stopMainLoop()
{

}

void SDL2WrapperAdapter::renderAllWindows()
{
    this->m_sdlW->renderFrame();
}

void SDL2WrapperAdapter::populatKeyStates( KeyMap& keysOut )
{
    auto& keys = this->m_sdlW->getKeyStates();
    for( const auto& key: keys )
    {
        auto keyConcrete = new IKeyConcrete();
        keyConcrete->setSDLKey( key.second.get() );
        std::shared_ptr<IKey> keyPtr( keyConcrete );
        keysOut[ key.first ] = keyPtr;
    }
}