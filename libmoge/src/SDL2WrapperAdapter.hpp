#pragma once
#include "IMainGameLoop.hpp"
#include "IKeyboardObservable.h"
#include "IRenderer2D.h"
#include "CUL/FS.hpp"
#include "SDL2Wrapper/ISDL2Wrapper.hpp"
#include "IKey.hpp"
#include <map>
namespace Moge
{
    class SDL2WrapperAdapter final:
        public IRenderer2D,
        public IKeyboardObservable,
        public IMainGameLoop,
        public SDL2W::IKeyboardObserver,
        private SDL2W::IWindowEventObserver
    {
    public:
        SDL2WrapperAdapter();

        ~SDL2WrapperAdapter();
        IWindow* createWindow(
            Vector3Du& size,
            Vector3Di& position,
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

    protected:
    private:
        SDL2W::ISDL2Wrapper* m_sdlW = nullptr;
    };
}