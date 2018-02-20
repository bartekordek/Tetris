#pragma once
#include "IWindow.hpp"
#include "IKeyboardObservable.h"
#include "IRenderer.h"
#include "IRenderer2D.h"
#include "IRenderer3D.h"
#include "IFPSCounter.h"
#include "IKey.hpp"

#include "IMainGameLoop.hpp"

namespace Moge
{
    class MogeLib_API IEngine: 
        public Moge::IKeyboardObservable
    {
    public:
        IEngine( void );
        virtual ~IEngine();

        virtual IWindow* createWindow( 
            CUL::Math::Vector3Du& size, 
            CUL::Math::Vector3Di& position, 
            const std::string& label = "Window label." )const = 0;
        virtual void startMainLoop() = 0;
        virtual void stopEventLoop() = 0;

        virtual void registerKeyboardObserver( IKeyboardObserver* observer ) override = 0;
        virtual void unregisterKeyboardObserver( IKeyboardObserver* observer ) override = 0;

        virtual void lockFps( unsigned fpsCount ) = 0;
        virtual void unlockFps() = 0;

        virtual const bool isKeyDown( const IKey* key )const = 0;

    protected:

    private:

    };
}