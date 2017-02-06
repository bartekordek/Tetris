#include "KeyboardObservable.h"
#include "KeyFactorySDL.h"
#include "IKey.h"

#include <SDL_events.h>
#include <iostream>
namespace Moge
{
	KeyboardObservable::KeyboardObservable(): sdlKey( SDL_GetKeyboardState( nullptr ) )
	{
		this->keyFactory.reset( new KeyFactorySDL() );
		this->keys = this->keyFactory->createKeys();
		this->poolThread = std::thread( &KeyboardObservable::poolLoop, this );
	}

	KeyboardObservable::~KeyboardObservable()
	{
		this->quitMutex.lock();
		this->runLoop = false;
		this->quitMutex.unlock();
		this->poolThread.join();
	}

	const bool KeyboardObservable::keyIsDown( const std::string& keyName ) const
	{
		const auto scanCode = static_cast<unsigned int>( SDL_GetScancodeFromName( keyName.c_str() ) );
		return this->keys.at(scanCode)->keyIsDown();
	}

	void KeyboardObservable::poolLoop()
	{
		SDL_Event event;
		this->quitMutex.lock();
		while( true == this->runLoop )
		{
			this->quitMutex.unlock();
			//auto waitResult = SDL_WaitEvent( &event )
			auto waitResult = SDL_PollEvent( &event );
			std::cout << "WAIT RESULT = " << waitResult << std::endl;
			if( waitResult > 0 )
			{
				auto scancode = SDL_GetScancodeFromKey( event.key.keysym.sym );
				if( SDL_SCANCODE_UNKNOWN != scancode )
				{
					const bool keyIsDown = ( SDL_KEYDOWN == event.type ) ? true : false;
					const auto keyIndex = static_cast<unsigned int>( scancode );
					auto key = this->keys.at( keyIndex ); 
					key->setKeyState( keyIsDown );
					this->notifyObservers( nullptr );
				}
			}
			this->quitMutex.lock();
		}
	}
}
