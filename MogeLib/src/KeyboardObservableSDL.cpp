#include "KeyboardObservableSDL.h"
#include "IKey.h"
#include "KeyFactorySDL.h"
#include <SDL.h>
using namespace Moge;
KeyboardObservableSDL::KeyboardObservableSDL(): m_runEventLoop( true ), sdlKey( SDL_GetKeyboardState( nullptr ) )
{
	this->keyFactory.reset( new KeyFactorySDL() );
	this->keys = this->keyFactory->createKeys();
}

KeyboardObservableSDL::~KeyboardObservableSDL()
{
}

void KeyboardObservableSDL::runEventLoop()
{
	SDL_Event event;
	while( true == this->m_runEventLoop )
	{
		if( SDL_WaitEvent( &event ) > 0 )
		{
			if( ( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP ) )
			{
				auto scancode = SDL_GetScancodeFromKey( event.key.keysym.sym );
				if( SDL_SCANCODE_UNKNOWN != scancode )
				{
					const bool keyIsDown = ( SDL_KEYDOWN == event.type ) ? true : false;
					const auto keyIndex = static_cast<unsigned int>( scancode );
					auto key = this->keys.at( keyIndex );
					key->setKeyIsDown( keyIsDown );
					this->notifyKeyboardObservers( key.get() );
				}
			}
		}
	}
}

void KeyboardObservableSDL::stopEventLoop()
{
	this->m_runEventLoop = false;
}