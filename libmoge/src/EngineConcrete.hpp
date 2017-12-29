#pragma once
#include "IEngine.h"

#include "LckPrim.h"
#include "FramesData.hpp"
#include "CUL/ITimer.hpp"

#include <map>
#include <thread>
#include <mutex>
#include <memory>

namespace Moge
{
    class EngineConcrete final: public IEngine
    {
    public:
        EngineConcrete( void );
        virtual ~EngineConcrete();

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
        LckPrim<bool> mainLoopIsRuning{ true };

        std::unique_ptr<INodeFactory> nodeFactory;

        std::unique_ptr<IRenderer2D> renderer2D;
        std::unique_ptr<IRenderer3D> renderer3D;

        std::unique_ptr<ITextureFactory3D> textureFactory3D;
        IMainGameLoop* m_mainGameLoop = nullptr;
        IKeyboardObservable* m_keyboardObservable;

        std::unique_ptr<IFPSCounter> fpsCounter;
        LckPrim<int> frameSleepTimeMs{ 0 };
        LckPrim<unsigned> infoLoopPrintDelayMs{ 2000 };

        LckPrim<double> targetFrameTimeMs{ 1000.0 / 60.0 };
        LckPrim<int> m_fpsCount{ 60 };
        std::unique_ptr<CUL::ITimer> timer;
        unsigned lastFrameTimeMs = static_cast<unsigned>( 1000.0 / 60.0 );
        double frameSleepMs = 10;
        FrameData m_frameData;
    };
}