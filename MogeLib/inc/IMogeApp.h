#pragma once

#include "IKeyboardObserver.h"
#include "Engine.h"

namespace Moge
{
	class IMogeApp: public IKeyboardObserver
	{
	public:
		MogeLib_API IMogeApp( void );
		MogeLib_API virtual ~IMogeApp();
		Engine* getEngine();
		MogeLib_API void startApp();
		
	protected:
	private:
		MogeLib_API virtual void initialize();
		virtual void frontEndLoop() = 0;
		void eventLoop();

		Engine* engine = nullptr;
		bool runMainLoop = true;
	};
}
