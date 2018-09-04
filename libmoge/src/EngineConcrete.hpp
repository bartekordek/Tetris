#pragma once
#include "IEngine.h"

#include "CUL/LckPrim.hpp"
#include "FramesData.hpp"
#include "CUL/ITimer.hpp"
#include "SDL2WrapperAdapter.hpp"

#include <map>
#include <thread>
#include <mutex>
#include <memory>

namespace Moge
{
    class EngineConcrete final:
        public IEngine
    {
    public:
        EngineConcrete( void );
        virtual ~EngineConcrete();

        IWindow* createWindow(
            const CUL::Math::Vector3Du& size,
            const CUL::Math::Vector3Di& position,
            const std::string& label = "Window label." )const override;
        void startMainLoop();
        void stopEventLoop();

        void registerKeyboardObserver( IKeyboardObserver* observer ) override;
        void unregisterKeyboardObserver( IKeyboardObserver* observer ) override;

        void lockFps( unsigned fpsCount );
        void unlockFps();

        const bool isKeyDown( const IKey* key )const override;
    protected:
    private:
        void mainLoop();
        void renderingLoop2D();
        void QueueFrame();
        void infoLoop();

        std::mutex mRenderableObjectsMutex;
        std::mutex mListMutex;
        std::thread m_mainLoop;
        std::thread infoLoopThread;
        CUL::LckPrim<bool> mainLoopIsRuning{ true };

        SDL2WrapperAdapter* sdlAdapter = nullptr;

        std::unique_ptr<IRenderer2D> renderer2D;
        std::unique_ptr<IRenderer3D> renderer3D;

        IMainGameLoop* m_mainGameLoop = nullptr;
        IKeyboardObservable* m_keyboardObservable;

        std::unique_ptr<IFPSCounter> fpsCounter;
        CUL::LckPrim<int> frameSleepTimeMs{ 0 };
        CUL::LckPrim<unsigned> infoLoopPrintDelayMs{ 2000 };

        CUL::LckPrim<double> targetFrameTimeMs{ 1000.0 / 60.0 };
        CUL::LckPrim<int> m_fpsCount{ 60 };
        std::unique_ptr<CUL::ITimer> timer;
        unsigned lastFrameTimeMs = static_cast<unsigned>( 1000.0 / 60.0 );
        double frameSleepMs = 10;
        FrameData m_frameData;
        std::map<IWindow*, std::shared_ptr<IWindow>> m_windows;
        KeyMap m_keys;
    };
}