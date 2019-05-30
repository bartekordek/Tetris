#pragma once
#include "IMainGameLoop.hpp"
#include "IKeyboardObservable.h"
#include "IRenderer2D.h"
#include "CUL/Filesystem/FS.hpp"
#include "SDL2Wrapper/ISDL2Wrapper.hpp"
#include "IKey.hpp"
#include <map>
#include <set>
namespace Moge
{
    using SDLKeybObs = SDL2W::IKeyboardObserver;
    using ObserverList = std::set<Moge::IKeyboardObserver*>;
    class SDL2WrapperAdapter final:
        public IRenderer2D,
        public Moge::IKeyboardObservable,
        public IMainGameLoop,
        public SDLKeybObs,
        private SDL2W::IWindowEventObserver
    {
    public:
        SDL2WrapperAdapter();

        ~SDL2WrapperAdapter();
        IWindow* createWindow(
            const Vector3Du& size,
            const Vector3Di& position,
            const std::string& winName = "Unnamed window." ) override;
        void forceDestroy() override;

        void updateScreen()override;
        void clear() override;

        void runMainLoop() override;
        void stopMainLoop() override;

        void renderAllWindows() override;

        void populatKeyStates( KeyMap& keys );

        void onKeyBoardEvent( const SDL2W::IKey& key ) override;
        void onWindowEvent( const WindowEventType e );

        void notifyKeyboardObservers( const IKey& data ) override;

        void registerKeyboardObserver( Moge::IKeyboardObserver* observer ) override;
        void unregisterKeyboardObserver( Moge::IKeyboardObserver* observer ) override;

    protected:
    private:
        void initializeKeys();

        SDL2W::ISDL2Wrapper* m_sdlW = nullptr;
        ObserverList m_observersList;
        KeyMap m_keyList;
    };
}