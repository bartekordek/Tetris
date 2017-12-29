#pragma once

#include "Singleton.h"
#include "IKeyboardObservable.h"
#include "INodeFactory.h"
#include "IRenderer.h"
#include "Math/ISize.h"
#include "IRenderer2D.h"
#include "IRenderer3D.h"
#include "ITextureFactory.h"
#include "IFPSCounter.h"

#include "IMainGameLoop.hpp"

namespace Moge
{
    class IKeyboardObserver;
    class IKeyboardData;
    class IKey;
    class IKeyFactory;
    class ITextureFactory3D;
    class MogeLib_API IEngine: 
        public IKeyboardObservable
    {
    public:
        IEngine( void );
        virtual ~IEngine();

        virtual void createScreen( Math::ISize<unsigned int>& size, Math::IPosition<int>& position, const std::string& label = "Window label." )const = 0;
        virtual void startMainLoop() = 0;
        virtual void stopEventLoop() = 0;
        virtual ITextureFactory* get2DTextureFactory()const = 0;
        virtual ITextureFactory* get3DTextureFactory()const = 0;
        virtual INodeFactory* get2DNodeFactory()const = 0;
        virtual INodeFactory* get3DNodeFactory()const = 0;

        virtual void registerObserver( IKeyboardObserver* observer ) override = 0;
        virtual void unregisterObserver( IKeyboardObserver* observer ) override = 0;

        virtual void lockFps( unsigned fpsCount ) = 0;
        virtual void unlockFps() = 0;

    protected:

    private:

    };
}