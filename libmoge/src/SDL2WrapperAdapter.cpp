#include "SDL2WrapperAdapter.hpp"
#include "SDLWindowAdapter.hpp"
#include "IKeyConcrete.hpp"

using namespace Moge;

SDL2WrapperAdapter::SDL2WrapperAdapter():
    m_sdlW( SDL2W::createSDL2Wrapper() )
{
    initializeKeys();
}

void SDL2WrapperAdapter::initializeKeys()
{
    auto& keys = this->m_sdlW->getKeyStates();
    for( const auto& key: keys )
    {
        std::shared_ptr<IKeyConcrete> keyPtr( new IKeyConcrete() );
        keyPtr->setSDLKey( key.second.get() );
        this->m_keyList[ keyPtr->getKeyName() ] = keyPtr;
    }
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
    auto sdlWin = this->m_sdlW->getWindowFactory()->createWindow(
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
    this->m_sdlW->stopEventLoop();
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
    notifyKeyboardObservers( *this->m_keyList[ key.getKeyName() ].get() );
}

void SDL2WrapperAdapter::onWindowEvent( const WindowEventType e )
{
    std::cout << "KEY IS " << static_cast<int>( e ) << "\n";
}

void SDL2WrapperAdapter::notifyKeyboardObservers( const IKey& key )
{
    for( auto& observer: this->m_observersList )
    {
        observer->onKeyboardEvent( key );
    }
}

void SDL2WrapperAdapter::registerKeyboardObserver( Moge::IKeyboardObserver* observer )
{
    this->m_observersList.insert( observer );
}

void SDL2WrapperAdapter::unregisterKeyboardObserver( Moge::IKeyboardObserver* observer )
{
    auto it = this->m_observersList.find( observer );
    if( it != this->m_observersList.end() )
    {
        this->m_observersList.erase( it );
    }
}