#pragma once

#include <map>
#include <thread>
#include <mutex>
#include <memory>

#include "Singleton.h"
#include "IKeyboardObservable.h"
#include "INodeFactory.h"
#include "IRenderer.h"
#include "Math/ISize.h"
#include "IRenderer2D.h"
#include "IRenderer3D.h"
#include "ITextureFactory.h"
#include "IFPSCounter.h"
#include "LckPrim.h"
#include "IMainGameLoop.hpp"

namespace Moge
{
    class IKeyboardObserver;
    class IKeyboardData;
    class IKey;
    class IKeyFactory;
    class ITextureFactory3D;
    class ITimer;
    class MogeLib_API Engine: 
        public Singleton<Engine>, 
        public IKeyboardObservable
    {
    public:
        Engine( void );
        virtual ~Engine();

        void createScreen( Math::ISize<unsigned int>& size, Math::IPosition<int>& position, const std::string& label = "Window label." )const;
        void startMainLoop();
        void stopEventLoop();
        ITextureFactory* get2DTextureFactory()const;
        ITextureFactory* get3DTextureFactory()const;
        INodeFactory* get2DNodeFactory()const;
        INodeFactory* get3DNodeFactory()const;

        void registerObserver( IKeyboardObserver* observer ) override;
        void unregisterObserver( IKeyboardObserver* observer ) override;

        void lockFps( unsigned fpsCount );
        void unlockFps();

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
        LckPrim<bool> mainLoopIsRuning;

        std::unique_ptr<INodeFactory> nodeFactory;
        
        std::unique_ptr<IRenderer2D> renderer2D;
        std::unique_ptr<IRenderer3D> renderer3D;
        
        std::unique_ptr<ITextureFactory3D> textureFactory3D;
        IMainGameLoop* m_mainGameLoop = nullptr;
        IKeyboardObservable* m_keyboardObservable;

        std::unique_ptr<IFPSCounter> fpsCounter;
        LckPrim<int> frameSleepTimeMs;
        int framesDelta = 2;
        int fpsConst = 60;
        LckPrim<unsigned> infoLoopPrintDelayMs { 2000 };


        LckPrim<double> targetFrameTime{ 1000.0 / 60.0 };
        LckPrim<int> m_fpsCount{ 60 };
        std::unique_ptr<ITimer> timer;
        unsigned lastFrameTimeMs = static_cast<unsigned>( 1000.0 / 60.0 );
        double frameSleepMs = 10;
    };
}