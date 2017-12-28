#pragma once

#include <thread>
#include "IKeyboardObserver.h"
#include "IEngine.h"

namespace Moge
{
    class IMogeApp: public IKeyboardObserver
    {
    public:
        MogeLib_API IMogeApp( void );
        MogeLib_API virtual ~IMogeApp();
        IEngine* getEngine();
        MogeLib_API void run();
        
    protected:
    private:
        MogeLib_API virtual void initialize();
        void frontEndLoopWrapper();
        virtual void frontEndLoop() = 0;
        void stopApp();

        IEngine* engine = nullptr;
        bool runMainLoop = true;
        std::thread frontEndLoopThread;
    };
}