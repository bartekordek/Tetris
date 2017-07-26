#pragma once

#include <thread>
#include "IKeyboardObserver.h"
#include "Engine.h"

namespace Moge
{
	class IMogeApp: public IKeyboardObserver
	{
	public:
		MogeLib_API IMogeApp( void );
		MogeLib_API virtual ~IMogeApp();
		const Engine* getEngine()const;
		MogeLib_API void run();
		
	protected:
	private:
		/* Override this method to set some initialization.*/
		MogeLib_API virtual void initialize();
		/* Override this method to set some additional cleaning.*/
		MogeLib_API virtual void clean();
		void frontEndLoopWrapper();
		/*
		 * Front End loop needs to have implementation.
		 * Engine will run as long as front end loop runs.
		 */
		virtual void frontEndLoop() = 0;

		Engine* engine = nullptr;
		bool runMainLoop = true;
		std::thread frontEndLoopThread;
	};
}
