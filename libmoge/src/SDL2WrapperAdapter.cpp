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
    this->m_sdlW->clearWindows();
}

void SDL2WrapperAdapter::runMainLoop()
{
    this->m_sdlW->registerKeyboardEventListener( this );
    this->m_sdlW->registerWindowEventListener( this );
    this->m_sdlW->runEventLoop();
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
#include <iostream>
void SDL2WrapperAdapter::onKeyBoardEvent( const SDL2W::IKey& key )
{
    std::cout << "KEY IS " << key.getKeyName() << "\n";
}

void SDL2WrapperAdapter::onWindowEvent( const WindowEventType e )
{
    std::cout << "KEY IS " << static_cast<int>( e ) << "\n";
}